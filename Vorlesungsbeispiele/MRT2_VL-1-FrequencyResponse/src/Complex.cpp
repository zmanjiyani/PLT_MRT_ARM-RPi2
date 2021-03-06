/**
 * @class Complex.cpp
 *
 * @brief An example for adding new types to c++
 *
 * This class is meant as an example and contains at least one intended
 * bug. Please consult the projects MRT2_VL-1-ComplexTest or
 * MRT2_VL-1-ComplexGoogleTest to locate the bug.
 *
 * @author uleon, leon.urbas@tu-dresden.de
 * @date   2016/04/04
 *
 */
#include <iostream>
#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imag(i)  {
	std::cerr << "DBG: Constructor real=" << r << ", imag=" << i << std::endl;
}
double Complex::Re() const {
	return real;
}
double Complex::Im() const {
	return imag;
}

Complex& Complex::operator+=(const Complex& rhs) {
		real+=rhs.real; imag+=rhs.imag;
		return *this;
}
Complex& Complex::operator-=(const Complex& rhs) {
		real-=rhs.real; imag-=rhs.imag;
		return *this;
}
Complex& Complex::operator*=(const Complex& rhs) {
		double r = real*rhs.real-imag*rhs.imag;
		double i  = real*rhs.imag+imag*rhs.real;
		real = r; imag = i; return *this;
}
Complex& Complex::operator/=(const Complex& rhs) {
		double d = rhs.real*rhs.real+rhs.imag*rhs.imag;
		double r = (real*rhs.real+imag*rhs.imag)/d;
		double i = (real*rhs.imag-imag*rhs.real)/d;
		real = r; imag = i; return *this;
}

std::ostream& operator<<(std::ostream& lhs, const Complex& rhs) {
   return lhs << rhs.Re() << "," << rhs.Im();
}

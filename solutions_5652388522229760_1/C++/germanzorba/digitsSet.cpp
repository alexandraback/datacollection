#include "digitsSet.h"

using namespace std;


dSet digitsSet(int number, int base) {
	if (number < 0) number = -number;
	dSet digits;
	while (number>0) {
		digits.insert(number%base);
		number /= base;
	}
	return digits;
}

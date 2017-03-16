#include <cstdio>
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

#define getchar_custom _fgetc_nolock

char c;

template <typename T>
inline T read_custom() {

	c = getchar_custom(stdin);

	while (c<'0' || c>'9')
	{
		c = getchar_custom(stdin);
	}

	T returnValue = 0;
	while (c >= '0' && c <= '9') {
		returnValue = (returnValue << 3) + (returnValue << 1) + c - 48;
		c = getchar_custom(stdin);
	}

	return returnValue;
}

int main() {

	int casesNo = read_custom<int>();

	for (int caseNo = 1; caseNo <= casesNo; caseNo++) {

		long output = 0;

		long a = read_custom<long>();
		long b = read_custom<long>();
		long k = read_custom<long>();

		for (long i = 0; i < a; i++) {
			for (long j = 0; j < b; j++) {
				if ((i & j) < k) {
					output++;
				}
			}
		}

		std::cout << "Case #" << caseNo << ": " << output << std::endl;
	}

}
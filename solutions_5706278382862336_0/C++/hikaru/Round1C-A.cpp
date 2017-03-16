#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <deque>
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <intrin.h>

template<typename Ty>
inline Ty gcd(Ty a, Ty b)
{
	Ty r;
	if (a < b) std::swap(a, b);
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");

	int T;
	fscanf(fp, "%d", &T);
	for (int t=1; t<=T; t++) {
		int P, Q;
		fscanf(fp, "%d/%d", &P, &Q);
		
		int g = gcd(P, Q);
		P /= g;
		Q /= g;

		bool b = false;
		int a = 1;
		for (int i = 1; i <= 40; i++) {
			a *= 2;
			if (Q == a) {
				b = true;
				break;
			}
		}

		int factor = 1;
		int result;
		for (result=1; result<=40; result++) {
			factor *= 2;
			if (P * factor >= Q) break;
		}
		if (result <= 40 && b) {
			printf("Case #%d: %d\n", t, result);
		} else {
			printf("Case #%d: impossible\n", t);
		}
	}

	return 0;
}

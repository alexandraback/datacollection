#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int T, t, X, Y, A, B, baseA, baseB, res, i;
	char Pasos[505], mA, MA, mB, MB;
	bool isA, bA, bB;
	scanf("%d\n", &T);
	for (int t=1 ; t<=T ; t++) {
		scanf("%d %d\n", &X, &Y);
		if (abs(X)>abs(Y)) {
			B = abs(X);
			A = abs(Y);
			if (X>0) {
				mB = 'W';
				MB = 'E';
			} else {
				mB = 'E';
				MB = 'W';
			}
			if (Y>0) {
				mA = 'S';
				MA = 'N';
			} else {
				mA = 'N';
				MA = 'S';
			}
		} else {
			B = abs(Y);
			A = abs(X);
			if (X>0) {
				mA = 'W';
				MA = 'E';
			} else {
				mA = 'E';
				MA = 'W';
			}
			if (Y>0) {
				mB = 'S';
				MB = 'N';
			} else {
				mB = 'N';
				MB = 'S';
			}
		}
		
		isA = true;
		bA = false;
		bB = false;
		baseA = 0;
		baseB = 0;
		for (i=1 ; i<=500 && !bA && !bB ; i++) {
			if (isA) {
				if (baseA + i > A) {
					bA = true;
					break;
				}
				baseA += i;
				Pasos[i-1] = MA;
			} else {
				if (baseB + i > B) {
					bB = true;
					break;
				}
				baseB += i;
				Pasos[i-1] = MB;
			}
			isA = !isA;
		}

		for (; i<= 500 ; i++) {
			if (!bA) {
				if (baseA + i > A) {
					break;
				}
				baseA += i;
				Pasos[i-1] = MA;
			} else if (!bB) {
				if (baseB + i > B) {
					break;
				}
				baseB += i;
				Pasos[i-1] = MB;
			}
		}
		for (int j=baseA ; j<A ; j++, i+=2) {
			Pasos[i-1] = mA;
			Pasos[i] = MA;
		}

		for (int j=baseB ; j<B ; j++, i+=2) {
			Pasos[i-1] = mB;
			Pasos[i] = MB;
		}

		Pasos[i-1] = '\0';

		printf("Case #%d: %s\n", t, Pasos);
	}
	return 0;
}

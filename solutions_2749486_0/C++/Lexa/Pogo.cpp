//============================================================================
// Name        : Pogo.cpp
// Author      : J.Son
// Version     :
// Copyright   : GNU LGPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);
	for(int cas = 1; cas <= cases; cas++) {
		int x, y;
		bool negX = false, negY = false;

		scanf("%d %d", &x, &y);
		printf("Case #%d: ", cas);
		if(x < 0) {
			x *= -1;
			negX = true;
		}

		if(y < 0) {
			y *= -1;
			negY = true;
		}
		if(negX) {
			for(int i = 0; i < x; i++) { printf("EW"); }
		} else {
			for(int i = 0; i < x; i++) { printf("WE"); }
		}

		if(negY) {
			for(int i = 0; i < y; i++) { printf("NS"); }
		} else {
			for(int i = 0; i < y; i++) { printf("SN"); }
		}
		printf("\n");
	}
	return 0;
}

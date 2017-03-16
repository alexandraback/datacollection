//============================================================================
// Name        : gcj_A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "fstream"
#include "string.h"
#include "stdio.h"
#include"cmath"
#define N 1000
#define M 40
using namespace std;
int a[N + 1];
int c[12];
int index;
int f(int t) {
	int result = 0;
	while (t > 0) {
		t /= 10;
		result++;
	}
	return result;
}
int myPow(int n) {
	int result = 1;
	for (int i = 0; i < n; ++i) {
		result *= 10;
	}
	return result;
}
int get(int n, int r) {
	return n / myPow(r - 1) % 10;
}
int main() {
	/*int n,t;
	 scanf("%d%d",&n,&t);
	 printf("%d\n",get(n,t));*/
	//freopen("b.in","r",stdin);
	freopen("c-small.out","w",stdout);

	int T;
	scanf("%d", &T);
	for (int ii = 0; ii < T; ++ii) {
		int A, B;
		scanf("%d%d", &A, &B);
		int result = 0;

		for (int i = A; i <= B; i++) {
			index = 0;
			int t = f(i);
			int temp = i;
			for (int j = 1; j < t; j++) {
				int w = get(temp, j);
				if (w != 0) {
					int h = temp / (myPow(j)) + temp % (myPow(j)) * (myPow(t
							- j));
					if (h > temp && h <= B && h >= A) {
						int k = 0;
						for (; k < index; k++) {
							if (c[k] == h)
								break;
						}
						if (k == index) {
							result++;
							//printf("%d %d\n", temp, h);
							c[index++]=h;
						}
					}
				}
			}
		}

		printf("Case #%d: %d\n", ii + 1, result);
	}

	return 0;
}

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#define _USE_MATH_DEFINES
using namespace std;

int main() {
	int t, x, y, count;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", i+1);
		if (x > 0) {
			while (x > 0) {
				printf("WE");
				x--;
			}
		}
		if (x < 0) {
			while (x < 0) {
				printf("EW");
				x++;
			}
		}
		if (y > 0) {
			while (y > 0) {
				printf("SN");
				y--;
			}
		}
		if (y < 0) {
			while (y < 0) {
				printf("NS");
				y++;
			}
		}
		printf("\n");
	}
	return 0;
}

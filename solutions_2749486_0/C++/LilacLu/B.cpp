#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>

#define SMALL
//#define LARGE

using namespace std;

int main()
{
#ifdef SMALL
	freopen("B_small.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
#endif
#ifdef LARGE
	freopen("B_large.in", "r", stdin);
	freopen("B_large.out", "w", stdout);
#endif

	int t, x, y;
	scanf("%d", &t);
	for (int Case = 1; Case <= t; ++Case) {
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", Case);
		if (x > 0) {
			for (int i = 1; i < x; ++i) {
				printf("EW");
			}
			printf("E");
		} else if (x < 0) {
			x *= -1;
			for (int i = 1; i < x; ++i) {
				printf("WE");
			}
			printf("W");
		}
		if (y < 0) {
			y *= -1;
			for (int i = 1; i <= y; ++i) {
				printf("NS");
			}
		} else if (y > 0) {
			for (int i = 1; i <= y; ++i) {
				printf("SN");
			}
		}
		printf("\n");
	}
	return 0;
}

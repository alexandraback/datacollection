#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 1010

int t;

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		if (r > c) {
			swap(r, c);
		}
		if (x >= 7) goto r;
		if (r*c%x != 0) goto r;
		switch (x) {
			case 3:
				if (r <= 1) goto r;
				goto g;
			case 4:
				if (r <= 2) goto r;
				goto g;
			case 5:
				if (r <= 2) goto r;
				if (r == 3 && c == 5) goto r;
				goto g;
			case 6:
				if (r <= 3) goto r;
				goto g;
		}
g:
		printf("Case #%d: GABRIEL\n", ti+1);
		continue;
r:
		printf("Case #%d: RICHARD\n", ti+1);
		continue;
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */

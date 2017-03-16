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

int t, sMax;
char s[NN];

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d%s", &sMax, s);
		int total = s[0] - '0';
		int extra = 0;
		for (int i = 1; i <= sMax; ++i) {
			int c = s[i] - '0';
			if (total < i) {
				extra += (i - total);
				total = i;
			}
			total += c;
		}
		printf("Case #%d: %d\n", ti, extra);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */

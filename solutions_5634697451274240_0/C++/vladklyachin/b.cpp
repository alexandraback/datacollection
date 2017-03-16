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
char s[NN];

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%s", s);
		auto ln = strlen(s);
		int count = 0;
		for (size_t i = 1; i < ln; ++i) {
			if (s[i-1] != s[i]) {
				++count;
			}
		}
		if (s[ln - 1] == '-') {
			++count;
		}
		printf("Case #%d: %d\n", ti+1, count);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */

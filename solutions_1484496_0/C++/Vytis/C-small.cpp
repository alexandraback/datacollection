#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define FILE_IN  "C-small-attempt0.in"
#define FILE_OUT "C-small-attempt0.out"

#define MAXN 20

void solve() {
	int n;
	int s[MAXN];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &s[i]);
	for (int u = 1; u < (1 << n); ++u) {
		int c = 0, sm = 0;
		int ss[MAXN], ssi = 0;
		for (int i = 0; i < n; ++i)
			if (u & (1 << i)) {
				++c;
				sm += s[i];
				ss[ssi++] = s[i];
			}
		if (sm % 2 != 0)
			continue;
		for (int m = 1; m < (1 << (ssi - 1)); ++m) {
			int ssm = 0;
			for (int i = 0; i < ssi; ++i)
				if (m & (1 << i))
					ssm += ss[i];
			if (ssm * 2 == sm) {
				bool f = true;
				for (int i = 0; i < ssi; ++i)
					if (m & (1 << i)) {
						if (f) f = false;
						else printf(" ");
						printf("%d", ss[i]);
					}
				printf("\n");
				f = true;
				for (int i = 0; i < ssi; ++i)
					if (!(m & (1 << i))) {
						if (f) f = false;
						else printf(" ");
						printf("%d", ss[i]);
					}
				printf("\n");
				return;
			}
		}
	}
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}

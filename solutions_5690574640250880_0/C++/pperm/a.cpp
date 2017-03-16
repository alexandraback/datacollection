#pragma comment(linker, "/STACK:128777216")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>
#include <windows.h>

typedef long long i64;
typedef unsigned int u32;
const int null = 0;

using namespace std;

template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T abs(const T &a) {
	return (a < 0? -a: a);
}
template<class T> T sqr(const T &a) {
	return a * a;
}

#define all(a) a.begin(),a.end()
char s[300][300];
int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		int n, m, x;
		cin >> n >> m >> x;
		bool isswap = false;
		if (n > m) {
			swap(n, m);
			isswap = true;
		}
		int all = n * m;
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; i++) {
			memset(s[i], '*', m);
		}
		x = all - x;
		bool g = true;
		if (x == 1) {
			s[0][0] = '.';
		} else if (n == 1) {
			for (int i = 0; i < x; i++) {
				s[0][i] = '.';
			}
		} else if (n == 2) {
			if ((x & 1) || x == 2) {
				g = false;
			} else {
				for (int i = 0; x; i ++) {
					s[0][i] = s[1][i] = '.';
					x -= 2;
				}
			}
		}
		else {
			if (x == 2 || x == 3 || x == 5 || x == 7) {
				g = false;
			} else {
				int row = 0;
				while (m + m + 2 <= x) {
					x -= m + m;
					for (int i = 0; i < m; i++) {
						s[row + 1][i] = s[row][i] = '.';
					}
					row += 2;
				}
				while (row > 0 && m + 2 <= x) {
					x -= m;
					for (int i = 0; i < m; i++) {
						s[row][i] = '.';
					}
					row++;
				}
				if (row == 0) {
					int w = (x & 1) ? (x - 3) / 2 : x / 2;
					x -= w + w;
					for (int i = 0; i < w; i++) {
						s[0][i] = s[1][i] = '.';
					}
					for (int i = 0; i < x; i++) {
						s[2][i] = '.';
					}
				} else {
					int w = (x <= m ? x : x - 2);
					x -= w;
					for (int i = 0; i < w; i++) {
						s[row][i] = '.';
					}
					row++;
					for (int i = 0; i < x; i++) {
						s[row][i] = '.';
					}
				}
			}
		}
		printf("Case #%d:\n", iTest);
		if (!g) {
			printf("Impossible\n");
		} else {
			s[0][0] = 'c';
			if (isswap) {
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j <= m; j++) {
						swap(s[i][j], s[j][i]);
					}
				}
				swap(n, m);
			}
			for (int i = 0; i < n; i++) {
				printf("%s\n", s[i]);
			}
		}
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}
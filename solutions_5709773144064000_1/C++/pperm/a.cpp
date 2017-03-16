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

int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		double c, f, x;
		cin >> c >> f >> x;
		double d = 0, u = x + 1;
		for (int i = 0; i < 100; i++) {
			double mid = (d + u) / 2;
			double p = 2;
			double rem = mid;
			bool g;
			while (!(g = p * rem > x)) {
				double t = c / p;
				if ((rem - t) * (p + f) < p * rem) {
					break;
				}
				else {
					rem -= t;
					p += f;
				}
			}
			if (g) {
				u = mid;
			} else {
				d = mid;
			}
		}
		printf("Case #%d: %.8lf\n", iTest, d);
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}
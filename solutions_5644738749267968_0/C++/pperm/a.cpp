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

set<double> scan(int n) {
	set<double> a;
	for (int i = 0; i < n; i++) {
		double t;
		scanf("%lf", &t);
		a.insert(t);
	}
	return a;
}

int solve1(set<double> a, set<double> b) {
	int score = 0;
	while (a.size()) {
		if (*a.begin() < *b.begin()) {
			b.erase(*b.rbegin());
		} else {
			b.erase(b.begin());
			score++;
		}
		a.erase(a.begin());
	}
	return score;
}

int solve2(set<double> a, set<double> b) {
	while (a.size()) {
		double t = *a.begin();
		set<double>::iterator it = b.lower_bound(t);
		if (it != b.end()) {
			b.erase(it);
		} else {
			return a.size();
		}
		a.erase(a.begin());
	}
	return 0;
}

int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		int n;
		cin >> n;
		set<double> a = scan(n), b = scan(n);
		printf("Case #%d: %d %d\n", iTest, solve1(a, b), solve2(a, b));
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}
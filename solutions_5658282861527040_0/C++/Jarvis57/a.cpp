//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i ++)
#define DOW(i, a, b) for(int i = a; i >= b; i --)
#define FOREACH(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it ++)
#define RESET(c, val) memset(c, val, sizeof(c))

int test, a, b, k;

int main() {
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	cin >> test;
	FOR(t, 1, test) {
		cin >> a >> b >> k;
		int res = 0;
		FOR(i, 0, a-1) FOR(j, 0, b-1) if ((i & j) < k) res ++;
		printf("Case #%d: %d\n", t, res);
	}
	return 0;
}

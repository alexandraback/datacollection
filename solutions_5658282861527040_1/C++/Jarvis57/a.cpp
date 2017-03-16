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

int test, A, B, K;
int a[100], b[100], k[100];
long long f[30][2][2][2];

long long get(int i, int ok1, int ok2, int ok) {
	if (f[i][ok1][ok2][ok] != -1) return f[i][ok1][ok2][ok];
	if (i == 12) {
		return 1;
	}
	f[i][ok1][ok2][ok] = 0;
	FOR(j, 0, 1) FOR(z, 0, 1) {
		if ((ok1 || j<=a[i]) && (ok2 || z<=b[i]) && (ok || (j&z)<=k[i])) {
			f[i][ok1][ok2][ok] += get(i+1, ok1 || (j<a[i]), 
										   ok2 || (z<b[i]),
										   ok  || (j&z) < k[i]);
		} 
	}
	return f[i][ok1][ok2][ok];
}

int main() {
	freopen("test.inp", "r", stdin);
	freopen("test.ans", "w", stdout);
	cin >> test;
	FOR(t, 1, test) {
		cin >> A >> B >> K;
		A--, B--, K--;
		DOW(i, 11, 0) a[i]=A%2, A/=2;
		DOW(i, 11, 0) b[i]=B%2, B/=2;
		DOW(i, 11, 0) k[i]=K%2, K/=2;

		RESET(f, -1);
		printf("Case #%d: %lld\n", t, get(0, 0, 0, 0));
	}
	return 0;
}

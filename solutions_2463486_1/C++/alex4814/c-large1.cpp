#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define EPS 1e-8
#define MAXN 100000
#define PI acos(-1.0)

typedef long long ll;
vector<ll> fair_sqr;

int T;
ll A, B;

int palindrome(long long x)
{
	int d[20];
	int n = 0;
	while (x) {
		d[n++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < n; ++i) {
		if (d[i] != d[n - 1 - i]) return 0;
	}
	return 1;
}

void pre()
{
	for (int i = 1; i <= 10000000; ++i) {
		if (!palindrome((ll)i)) continue;
		if (!palindrome((ll)i * i)) continue;
		fair_sqr.push_back((ll)i * i);
	}
}

int main()
{
	pre();
	scanf("%d", &T);
	for (int c = 1; c <= T; ++c) {
		cin >> A >> B;
		vector<ll>::iterator it1 = lower_bound(fair_sqr.begin(), fair_sqr.end(), A);
		vector<ll>::iterator it2 = upper_bound(fair_sqr.begin(), fair_sqr.end(), B);
		int ans = it2 - it1;
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}

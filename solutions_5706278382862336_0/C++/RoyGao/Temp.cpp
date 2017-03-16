#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define LL long long

const int maxn = 2005;
LL p, q;
char ch;

LL gcd(LL a, LL b)
{
	if (b%a == 0) return a;
	else return gcd(b%a, a);
}

bool check(LL x)
{
	while (x > 1) {
		if (x & 1) return false;
		x >>= 1;
	}
	return true;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		scanf("%I64d%c%I64d", &p, &ch, &q);
		printf("Case #%d: ", cas);
		LL t = gcd(p, q);
		p /= t;
		q /= t;
		if (!check(q)) puts("impossible");
		else {
			int ans = 0;
			while (p < q) {
				p <<= 1;
				ans++;
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}


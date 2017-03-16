#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8
#define MAXN 105
#define MAXE 1005

typedef pair<int, int> pii;
typedef long long ll;

int T;
ll P, Q;
ll f[50];
char s[MAXN];

ll gcd(ll a, ll b) {
	while (b ^= a ^= b ^= a %= b);
	return a;
}

bool power_of_two(ll n) {
	for (int i = 0; i < 50; ++i) {
		if (n == f[i]) return true; 
	}
	return false;
}

void init() {
	f[0] = 1;
	for (int i = 1; i < 50; ++i) {
		f[i] = f[i - 1] * 2;
	}
}

int main() {
	init();

	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%s", s);
		sscanf(s, "%lld/%lld", &P, &Q);
		ll g = gcd(P, Q);
		P /= g, Q /= g;

		if (!power_of_two(Q)) {
			printf("Case #%d: impossible\n", nCase);
			continue;
		}

		int ret = 0;
		while (P < Q) {	
			Q >>= 1;
			++ret;
		}
		printf("Case #%d: %d\n", nCase, ret);
	}

	return 0;
}



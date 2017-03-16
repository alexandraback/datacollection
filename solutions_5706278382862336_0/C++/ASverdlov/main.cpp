#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
#define db(v) cout << #v << " = " << (v) << endl;
typedef long long ll;

ll P, Q;
int T;

bool isPowOf(ll v)
{
	ll i = 1;
	while (i < v) i <<= 1;
	return i == v;
}

ll gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		printf("Case #%d: ", t + 1);
		char c;
		cin >> P >> c >> Q;
		ll M = gcd(P, Q);
		P /= M; Q /= M;

		int ans = 0;
		while (P < Q) P <<= 1, ++ans;
		if (!isPowOf(Q)) ans = -1;

		if (ans == -1) printf("impossible\n");
		else printf("%d\n", ans);
	}

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <ctime>

typedef long long ll;

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ZERO(x) memset((x), 0, sizeof(x))

using namespace std;

const int D = 1e7;

int nonprime[D];

ll binpow(ll deg, ll n, ll mod)
{
	if (deg == 0) return 1 % mod;
	if (deg & 1) return n * binpow(deg - 1, n, mod) % mod;
	ll b = binpow(deg / 2, n, mod);
	return b * b % mod;
}

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int w = 0; w < t; w++)
	{
		printf("Case #1:\n");
		vector<int> primes;
		for (int i = 2; i < D; i++)
		{
			if (nonprime[i]) continue;
			primes.push_back(i);
			for (int j = 2 * i; j < D; j += i)
				nonprime[j] = 1;
		}
		int n, j;
		cin >> n >> j;
		for (ll i = 0; i < (1 << (n - 2)); i++)
		{
			if (j == 0) break;
			ll q;
			vector<int> ans;
			for (int k = 2; k <= 10; k++)
			{
				ll t = 0;
				ll curpow = 1;
				ll g = i;
				g <<= 1;
				g |= 1;
				g |= (1LL << (n - 1));
				q = g;
				bool ok = 0;
				for (int e = 0; e < primes.size(); e++)
				{
					ll mod = 0;
					for (int d = 0; d < n; d++)
					{
						if ((g >> d) & 1)
						{
							mod = (mod + binpow(d, k, primes[e])) % primes[e];
						}
					}

					if (mod == 0)
					{
						ans.push_back(primes[e]);
						ok = 1;
						break;
					}
				}
				if (!ok) goto cannot;
			}
			for (int d = 0; d < n; d++)
				cout << ((q >> (n - d - 1)) & 1);
			cout << ' ';
			for (auto el : ans) cout << el << ' ';
			if (j != 1) cout << endl;
			j--;
			cannot:;
		}
	}

	return 0;
}
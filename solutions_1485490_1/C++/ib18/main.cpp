#pragma comment(linker, "/STACK:25600000")
#define _CRT_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(ll i=0; i<n; i++)
#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define RFOR(i, x, y) for(ll i=x; i>=y; i--)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define PII pair<ll, ll>
const double pi=acos(-1.0);
const double eps = 1e-9;
const double INF = 1000000000000000;

ll n, m;
ll A[128], B[128];
ll a[128], b[128];
ll dp[128][128];
ll s[256];

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("c-large.txt", "w", stdout);

	int tests;
	cin >> tests;
	REP(TEST, tests)
	{
		scanf("%lld%lld", &n, &m);
		FOR(i, 1, n)
			scanf("%lld%d", &a[i], &A[i]);
		FOR(i, 1, m)
			scanf("%lld%d", &b[i], &B[i]);

		memset(dp, 0, sizeof dp);
		ll ans = 0;
		FOR(i, 0, n)
			FOR(j, 0, m)
			{
				if (i) dp[i][j] = max(dp[i][j], dp[i-1][j]);
				if (j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
				ans = max(dp[i][j], ans);
				if (i == n || j == m) continue;
				if (A[i+1] != B[j+1]) continue;

				ll sum = 0; ll N = 0;
				FOR(k, i + 1, n)
					if (A[k] == A[i+1])
					{
						sum += a[k];
						s[N] = sum;
						++N;
					}

				sum = 0;
				FOR(k, j + 1, m)
					if (B[k] == B[j+1])
					{
						sum += b[k];
						s[N] = sum;
						++N;
					}

				sort(s, s + N);
				ll i1 = i;
				ll j1 = j;
				ll s1 = 0;
				ll s2 = 0;

				REP(k, N)
				{
					while(s1 < s[k])
					{
						if (s1 < s[k] && i1 == n) goto m1;
						++i1;
						if (A[i1] == A[i+1])
							s1 += a[i1];
					}
					
					while(s2 < s[k])
					{
						if (s2 < s[k] && j1 == m) goto m1;
						++j1;
						if (B[j1] == B[j+1])
							s2 += b[j1];

					}
					dp[i1][j1] = max(dp[i1][j1], dp[i][j] + s[k]);
					ans = max(ans, dp[i1][j1]);
				}
m1:;
			}
		printf("Case #%lld: %lld\n", TEST + 1, ans);
	}
}
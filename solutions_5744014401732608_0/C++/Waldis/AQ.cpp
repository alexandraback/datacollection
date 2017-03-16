#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <set>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <ctime>
#include <queue>
#include <map>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef bool bl;
typedef pair<bl, bl> pbl;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair
#define ft first
#define sd second
#define forn(i, y, x) for(int i = y; i < x; i++)
#define ford(i, y, x) for(int i = y; i >= x; i--)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define error exit(1)
#define DEBUG
const int mod = (int)1e9;
const ll inf = (ll)2e18;
const int base = 1000 * 1000 * 1000;
const int maxn = 2005;
const ld pi = acosl(-1.0);
const ld eps = 1e-9;

void solve()
{
	int t;
	scanf("%d", &t);
	forn(tt, 1, t + 1){
		ll n, m;
		scanf("%I64d %I64d", &n, &m);
		ll pw[64] = { 0 };
		bool flag = false;
		forn(i, 0, 64){
			ll cnt = (1LL << i);
			if (cnt & m) pw[i]++;
			if (cnt == m) flag = true;
		}
		int g[55][55] = {0};
		int maxr = 0;
		forn(i, 0, 64) if (pw[i]){
			maxr = i;
		}
		if ((flag && n - 2 < maxr) || (!flag && n - 3 < maxr)){
			printf("Case #%d: IMPOSSIBLE\n", tt);
			continue;
		}
		printf("Case #%d: POSSIBLE\n", tt);
		forn(i, 0, maxr + 1){
			forn(j, i + 1, maxr + 2){
				if (j == maxr + 1 && flag) g[i][n - 1] = 1;
				else g[i][j] = 1;
			}
		}
		if (!flag){
			forn(i, 0, maxr + 1) if (pw[i]){
				g[i + 1][n - 1] = 1;
			}
		}
		forn(i, 0, n){
			forn(j, 0, n) printf("%d", g[i][j]);
			printf("\n");
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
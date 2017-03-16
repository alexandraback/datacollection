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

inline ll get(char c){
	return (c - '0');
}

int dig(ll n){
	int res = 0;
	if (n == 0) return 1;
	while (n){
		res++;
		n /= 10;
	}
	return res;
}

void solve()
{
	int t;
	//scanf("%d", &t);
	cin >> t;
	forn(tt, 1, t + 1){
		string c, s;
		cin >> c >> s;
		ll pw[20] = { 0 };
		pw[17] = 1;
		ford(i, 16, 0) pw[i] = pw[i + 1] * 10LL;

		pll dp[20];

		pll ans = mp(0, 0);
		ford(r, sz(c) - 1, 0){
			pll cur = mp(0, inf);
			ll d1, d2;
			forn(i, 0, 10){
				if (c[r] == '?') d1 = ans.ft + i * pw[18 - sz(c) + r];
				else d1 = ans.ft + get(c[r]) * pw[18 - sz(c) + r];
				forn(j, 0, 10){
					if (s[r] == '?') d2 = ans.sd + j * pw[18 - sz(c) + r];
					else d2 = ans.sd + get(s[r]) * pw[18 - sz(c) + r];
					if (abs(cur.ft - cur.sd) > abs(d1 - d2))
						cur = mp(d1, d2);
				}
			}
			dp[r] = cur;
			ans = cur;
		}

		ans = mp(0, 0);
		forn(r, 0, sz(c)){
			pll cur = mp(0, inf);
			ll d1, d2, del1 = 0, del2 = 0;
			forn(i, 0, 10){
				if (c[r] == '?') d1 = ans.ft + i * pw[18 - sz(c) + r];
				else d1 = ans.ft + get(c[r]) * pw[18 - sz(c) + r];
				if (r + 1 != sz(c)) del1 = dp[r + 1].ft;
				d1 += del1;
				forn(j, 0, 10){
					if (s[r] == '?') d2 = ans.sd + j * pw[18 - sz(c) + r];
					else d2 = ans.sd + get(s[r]) * pw[18 - sz(c) + r];
					if (r + 1 != sz(c)) del2 = dp[r + 1].sd;
					d2 += del2;
					if (abs(cur.ft - cur.sd) > abs(d1 - d2))
						cur = mp(d1, d2);
				}
			}
			ans = mp(cur.ft - del1, cur.sd - del2);
		}
		cout << "Case #" << tt << ": ";
		cout << string(sz(c) - dig(ans.ft), '0') << ans.ft << ' ';
		cout << string(sz(s) - dig(ans.sd), '0') << ans.sd << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
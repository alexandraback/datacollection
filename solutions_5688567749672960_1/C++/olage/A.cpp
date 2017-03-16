#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <deque>
#include <ctime>
#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

#define endl '\n'

#define forr(i, n) for(ll (i) = 0LL; (i) < (n); (i)++)
#define mp3(a, b, c) mp(a, mp(b, c))

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;
typedef vector < pll > vll;

int INT_MAX_VAL = (int) 1e20;
int INT_MIN_VAL = (int) -1e20;
ll LONG_MAX_VAL = (ll) 1e20;
ll LONG_MIN_VAL = (ll) -1e20;

#define MAXN 100005

ll dp[MAXN];


ll rev(ll i)
{
//	cout << "rev: " << i << endl;
	if(i == 0) return 0;
	while(i % 10 == 0) i /= 10;
	ll res = 0;
	while(i) {
		res = 10 * res + (i % 10);
		i /= 10;
	}
	return res;
}

ll rec_solve(ll i)
{
	cerr << i << endl;
	if(i < 10) return i;
	if(i > MAXN) {
		return LONG_MAX_VAL;
	}

	if(dp[i] != 0) {
		return dp[i];
	}

	ll res = rec_solve(i - 1);

	ll ri = rev(i);
	if(ri < i) {
		res = min(res, rec_solve(ri));
	}

	dp[i] = res + 1;
	return dp[i];
}

ll bit_cnt(ll n)
{
	ll res = 1;
	while(n >= 10) {
		res *= 10;
		n /= 10;
	}
	return res;
}

ll drop_right(ll n)
{
	ll q = n;
	ll i = 0;
	while(q) {
		q /= 10;
		++i;
	}

	ll p = 1;
	ll res = 0;
	for(int j = 0; 2 * j < i; ++j) {
		res += p * (n % 10);
		n /= 10;
		p *= 10;
	}
	return res;
}

void solve(int T)
{
	cout << "Case #" << T << ": ";

	ll n; cin >> n;
	ll res = 0;
	while(true) {
		//		cerr << n << endl;
		if(n < 10) {
			res += n;
			break;
		}

		if(n % 10 == 0) {
			--n;
			++res;
		}
		ll dr = drop_right(n) - 1;
		ll cnt = bit_cnt(n);
		if(cnt + 1 == n) {
			n -= 2;
			res += 2;
		} else {
			n -= dr;
			n = rev(n);
			if(drop_right(n) > 1) {
				res += 1;
			}
			res += dr;
		}
	}

	cout << res << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	//	memset(dp, 0x3F, MAXN * sizeof(ll));
/*
	for(int i = 0; i < MAXN; ++i) {
		dp[i] = LONG_MAX_VAL;
	}

	dp[1] = 1;
	for(int i = 1; i + 1 < MAXN; ++i) {
		ll ri = rev(i);
		//		cout << i << " " << dp[i] << "    " << dp[i + 1] << " " << dp[ri] << endl;
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if(ri > i && ri < MAXN) {
			dp[ri] = min(dp[ri], dp[i] + 1);
		}

	}
*/
	int t; cin >> t;
	forr(i, t) solve(i + 1);

	return 0;
}

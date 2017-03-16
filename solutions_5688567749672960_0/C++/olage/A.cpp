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

#define MAXN 10000005

ll dp[MAXN];


ll rev(ll i)
{
//	cout << "rev: " << i << endl;
	if(i == 0) return 0;
	while(i % 10 == 0) i /= 10;
	int res = 0;
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


void solve(int T)
{
	cout << "Case #" << T << ": ";
	
	ll n; cin >> n;
	cout << dp[n] << endl;
//	cout << rec_solve(n) << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

//	memset(dp, 0x3F, MAXN * sizeof(ll));

	for(int i = 0; i < MAXN; ++i) {
		dp[i] = LONG_MAX_VAL;
	}

	dp[1] = 1;
	for(int i = 1; i + 1 < MAXN; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		ll ri = rev(i);
		if(ri > i && ri < MAXN) {
			dp[ri] = min(dp[ri], dp[i] + 1);
		}
	}

	int t; cin >> t;
	forr(i, t) solve(i + 1);

	return 0;
}

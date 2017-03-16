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

void solve(int t)
{
	string s; cin >> s >> s;
	int res = 0;
	int cur = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(i != 0 && cur < i) {
			res += (i - cur);
			cur = i;
		}
		cur += s[i] - '0';
	}
	cout << "Case #" << t << ": " << res << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	forr(t, T) solve(t + 1);

	return 0;
}

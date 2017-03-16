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


int dfs(vector<int> p)
{
	bool is_end = true;
	for(int i = 0; i < p.size(); ++i) {
		cout << p[i] << " ";
		if(p[i] != 0) is_end = false;
	}
	cout << endl;
	if(is_end) {
		return 0;
	}

	vector<int> p1 = p;
	for(int i = 0; i < p.size(); ++i) {
		p1[i] = max(0, p1[i] - 1);
	}

	int res1 = dfs(p1);


	int res2 = 0x3F3F3F3F;
	sort(p.begin(), p.end());
	if(p.back() > 1) {
		int q = p.back();
		p.push_back(0);
		for(int i = 1; i < q; ++i) {
			p[p.size() - 1] = i;
			p[p.size() - 2] = q - i;
			res2 = min(res2, dfs(p));
		}

	}

	return min(res1, res2) + 1;	
}

void solve(int t)
{
	int d; cin >> d;
	vector<int> p(d);
	for(int i = 0; i < d; ++i) cin >> p[i];

	int res = 0x3F3F3F3F;
	for(int z = 1; z < 10000; ++z) {
		int cur = z;
		for(int i = 0; i < d; ++i) {
			cur += (p[i] - 1) / z;
		}
		res = min(res, cur);
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

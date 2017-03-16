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

/*
 * 1: 1
 * i: 2
 * j: 3
 * k: 4
 */

int mult(int a, int b)
{
	int sign = 1;
	if(a < 0) { sign *= -1; a *= -1; }
	if(b < 0) { sign *= -1; b *= -1; }

	int res[4][4] = 
	{{1,  2,  3,  4},
	 {2, -1,  4, -3},
	 {3, -4, -1,  2},
	 {4,  3, -2, -1}};

//	cout << b << " " << a << endl;
	return sign * res[a - 1][b - 1];
}

int to_int(char b)
{
	switch(b) {
		case 'i': return 2;
		case 'j': return 3;
		case 'k': return 4;
	};
}

int mult(const string &s)
{
	int cur = 1;
	for(int i = 0; i < s.size(); ++i) {
		cur = mult(cur, s[i]);
	}
	return cur;
}

bool try_split(string s)
{
	//cout << s << endl;
	vector<int> pref(s.size()), sufx(s.size());
	pref[0] = to_int(s[0]);
	for(int i = 1; i < pref.size(); ++i) {
		pref[i] = mult(pref[i - 1], to_int(s[i]));
	}

	sufx[s.size() - 1] = to_int(s[s.size() - 1]);
	for(int i = s.size() - 2; i >= 0; --i) {
		sufx[i] = mult(to_int(s[i]), sufx[i + 1]);
	}

	for(int i = 0; i < s.size(); ++i) {
		if(pref[i] != to_int('i')) continue;
		int mid = 1;
		for(int j = i + 1; (j + 1) < s.size(); ++j) {
			mid = mult(mid, to_int(s[j]));
	//		cout << mid << endl;

			if(mid == to_int('j') && sufx[j + 1] == to_int('k')) {
	//			cout << pref[i] << " " << mid << " " << sufx[j + 1] << endl;
	//			cout << i << " " << j << endl;
				return true;
			}
		}
	}

	return false;
	
}

void solve(int t)
{
	long long x, l; cin >> l >> x;
	string s; cin >> s;


	int n = x % 4;
	if(x >= 4) n += 4;

	string ls;
	for(int i = 0; i < n; ++i) {
		ls += s;
	}

	bool res = try_split(ls);

	cout << "Case #" << t << ": ";
	if(res) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	forr(t, T) solve(t + 1);

	return 0;
}

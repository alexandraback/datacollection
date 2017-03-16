/*
 * b.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: AhmedHamza
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <complex>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define repall(it,m) for(__typeof(m.begin()) it=m.begin();it!=m.end();++it)
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

int DP[1000][1000];
int n, p;
map<int, vii> normal;
map<int, vii> surp;
int v[1000];

int dp(int ind, int s) {
	if (ind >= n)
		return 0;
	int &ret = DP[ind][s];
	if (ret != -1)
		return ret;
	ret = max(ret, dp(ind + 1, s) + (normal[v[ind]][0].back() >= p));
	if (s && surp[v[ind]].size())
		ret = max(ret, dp(ind + 1, s - 1) + (surp[v[ind]][0].back() >= p));
	return ret;
}

#define SMALL_INPUT

int main() {
#ifdef SMALL_INPUT
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("b-small.out", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("b-large.in", "rt", stdin);
	freopen("b-large.out", "wt", stdout);
#endif

	rep(i,11) {
		for (int j = i; j < 11; ++j) {
			if (abs(i - j) > 2)
				continue;
			for (int k = j; k < 11; ++k) {
				if (abs(i - k) > 2 || abs(j - k) > 2)
					continue;
				vi t;
				t.pb(i);
				t.pb(j);
				t.pb(k);
				if (abs(i - j) == 2 || abs(i - k) == 2 || abs(j - k) == 2)
					surp[i + j + k].pb(t);
				else
					normal[i + j + k].pb(t);
			}
		}
	}

//	repall(it,normal) {
//		cout << it->first << " => [";
//		rep(i,it->second.size()) {
//			if (i)
//				cout << ", ";
//			cout << "{";
//			rep(j,it->second[i].size()) {
//				if (j)
//					cout << ", ";
//				cout << it->second[i][j];
//			}
//			cout << "}";
//		}
//		cout << "]" << endl;
//	}
//
//	repall(it,surp) {
//		cout << it->first << " => [";
//		rep(i,it->second.size()) {
//			if (i)
//				cout << ", ";
//			cout << "{";
//			rep(j,it->second[i].size()) {
//				if (j)
//					cout << ", ";
//				cout << it->second[i][j];
//			}
//			cout << "}";
//		}
//		cout << "]" << endl;
//	}

//	return 0;

	int tc;
	cin >> tc;
	rep(T,tc) {
		int s;
		int ans = 0;
		cin >> n >> s >> p;
		rep(i,n)
			cin >> v[i];

		mem(DP, -1);
		ans = dp(0, s);

		cout << "Case #" << T + 1 << ": " << ans << endl;
	}
	return 0;
}


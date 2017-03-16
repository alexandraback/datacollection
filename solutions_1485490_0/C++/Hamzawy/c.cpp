/*
 * c.cpp
 *
 *  Created on: May 6, 2012
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
#ifdef _MSC_VER
#define rep(i,m) for(decltype(m) i=0;i<m;i++)
#define repI(i,m) for(decltype(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(decltype(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#else
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define repI(i,m) for(__typeof(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(__typeof(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define EPS (1e-9)
typedef stringstream ss;
typedef pair<long long, long long> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<long long> vi;
typedef vector<vector<long long> > vii;
typedef long long ll;

pii a[101];
pii b[101];
int n, m;

//ll DP[101][101];
map<pair<pair<int, int> ,pair<ll, ll> > ,ll> DP;
ll dp(int i, int j, ll aa, ll bb) {
	if (i >= n || j >= m)
		return 0;
	if (aa == 0)
		return dp(i + 1, j, a[i + 1].first, bb);
	if (bb == 0)
		return dp(i, j + 1, aa, b[j + 1].first);

	//ll& ret = DP[i][j];
	pair<pair<int, int> ,pair<ll, ll> > x = mp(mp(i, j), mp(aa, bb));
	if (DP.find(x) != DP.end())
		return DP[x];
//	if (ret != -1)
//		return ret;
	ll ret = -1;
//	ret = max(dp(i, j + 1, aa, b[j + 1].first),
//			dp(i + 1, j, a[i + 1].first, bb));
	ll y = 0;
	if (a[i].second == b[j].second) {
		y = min(aa, bb);
//		if (aa == y && bb != y)
//			ret = max(ret, y + dp(i + 1, j, a[i + 1].first, bb - y));
//		else if (bb == y && aa != y)
//			ret = max(ret, y + dp(i, j + 1, aa - y, b[j + 1].first));
//		else
	}
	ret = max(ret, y + dp(i, j + 1, aa - y, b[j + 1].first));
	ret = max(ret, y + dp(i + 1, j, a[i + 1].first, bb - y));
//	}
	return DP[x] = ret;
//	return ret;
}
#define SMALL_INPUT
int main() {
	freopen("c.in", "rt", stdin);
//	freopen("c.txt", "wt", stdout);
//	cout << 100 << endl;
//	rep(i,100) {
//		cout << 100 << " " << 100 << endl;
//		rep(j,100)
//			cout << 10000000000000000ll << " " << 100 << " ";
//		cout << endl;
//		rep(j,100)
//			cout << 10000000000000000ll << " " << 100 << " ";
//		cout << endl;
//	}
//	return 0;
#ifdef SMALL_INPUT
	freopen("c-small-attempt1.in", "rt", stdin);
	freopen("c-small.out", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("c-large.in", "rt", stdin);
	freopen("c-large.out", "wt", stdout);
#endif
	int tc;
	cin >> tc;
	rep(T,tc) {
		cin >> n >> m;
		rep(i,n)
			cin >> a[i].first >> a[i].second;
		rep(i,m)
			cin >> b[i].first >> b[i].second;
//		bool f = 1;
//		while (f) {
//			f = 0;
//			for (int i = 1; i < n; ++i) {
//				if (a[i].second == a[i - 1].second) {
//					a[i - 1].first += a[i].first;
//					for (int j = i + 1; j < n; ++j) {
//						a[j - 1] = a[j];
//					}
//					--n;
//					f = 1;
//				}
//			}
//		}
//
//		f = 1;
//		while (f) {
//			f = 0;
//			for (int i = 1; i < m; ++i) {
//				if (b[i].second == b[i - 1].second) {
//					b[i - 1].first += b[i].first;
//					for (int j = i + 1; j < m; ++j) {
//						b[j - 1] = b[j];
//					}
//					--m;
//					f = 1;
//				}
//			}
//		}

//		mem(DP, -1);
		DP.clear();
		ll ans = dp(0, 0, a[0].first, b[0].first);
		cout << "Case #" << T + 1 << ": ";
		cout << ans;
		cout << endl;
#ifdef SMALL_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T+1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}

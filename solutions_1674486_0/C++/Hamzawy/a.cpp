/*
 * a.cpp
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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

bool vis[100001];

vii v;
int root;
bool dfs(int ind) {
	if (vis[ind] && root != ind)
		return 1;
	if (vis[ind])
		return 0;
	vis[ind] = 1;
	rep(i,v[ind].size()) {
		if (dfs(v[ind][i]))
			return 1;
	}
	return 0;
}
#define SMALL_INPUT
int main() {
	//freopen("a.in", "rt", stdin);
#ifdef SMALL_INPUT
	freopen("A-small-attempt0.in.txt", "rt", stdin);
	freopen("a-small.out", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("a-large.in", "rt", stdin);
	freopen("a-large.out", "wt", stdout);
#endif
	int tc;
	cin >> tc;
	rep(T,tc) {
		int n, m, x;
		cin>>n;
		v.clear();
		v.resize(n);
		rep(i,n) {
			cin >> m;
			rep(j,m) {
				cin >> x;
				v[i].pb(x - 1);
			}
		}
		bool f = 0;
		rep(i,n) {
			root = i;
			mem(vis, 0);
			f |= dfs(i);
			if (f)
				break;
		}

		//
		cout << "Case #" << T + 1 << ": ";
		if (f)
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
#ifdef SMALL_INPUT
		cerr << T+1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T+1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}

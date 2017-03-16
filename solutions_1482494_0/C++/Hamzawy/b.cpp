/*
 * b.cpp
 *
 *  Created on: Apr 28, 2012
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
#define sz size()
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

pii v[100001];
int cnt, ans;

class cmp {
public:
	bool operator()(const int& a, const int& b) const {
//		pii x = mp(v[a].second, v[a].first), y = mp(v[b].second, v[b].first);
//		return x > y;
		if (v[a].second <= cnt || v[b].second > cnt) {
			return false;
		}
		if (v[a].second > cnt || v[b].second <= cnt) {
			return true;
		}
		if (v[a].first <= cnt || v[b].first > cnt) {
			return false;
		}
		if (v[a].second > cnt || v[b].second < cnt) {
			return true;
		}
		return v[a] > v[b];
	}
};
#define SMALL_INPUT
int main() {
#ifdef SMALL_INPUT
	freopen("B-small-attempt3.in", "rt", stdin);
	freopen("b-small.out.txt1", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("b-large.in", "rt", stdin);
	freopen("b-large.out", "wt", stdout);
#endif
	int tc;
	cin >> tc;
	rep(T,tc) {

		int n;
		cin >> n;
		rep(i,n)
			cin >> v[i].first >> v[i].second;

		cnt = 0;
		ans = 0;

		priority_queue<int, vector<int>, cmp> q;
		vector<vector<bool> > vis(n, vector<bool>(0));
		rep(i,n) {

			if (v[i].second <= cnt) {
				q.push(i);
			} else if (v[i].first <= cnt) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int ind = q.top();
			//cout << ind << endl;
			q.pop();
			if (v[ind].second <= cnt) {
				if (!vis[ind][1] && !vis[ind][0])
					cnt += 2;
				else if (!vis[ind][1])
					cnt += 1;
				else
					continue;
				ans++;
				vis[ind][1] = 1;
			} else if (v[ind].first <= cnt) {
				if (!vis[ind][1] && !vis[ind][0])
					cnt += 1;
				else
					continue;
				ans++;
				vis[ind][0] = 1;
			}
			rep(i,n) {
				if (v[i].second <= cnt && !vis[i][1]) {
					q.push(i);
				} else if (v[i].first <= cnt && !vis[i][0] && !vis[i][1]) {
					q.push(i);
				}
			}
		}

		bool f = 1;
		rep(i,n) {
			f &= vis[i][1];
		}
		if (f)
			cout << "Case #" << T + 1 << ": " << ans << endl;
		else
			cout << "Case #" << T + 1 << ": Too Bad" << endl;
	}
	return 0;
}


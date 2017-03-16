/*
 TASK:A
 LANG:C++
 Muhammad Magdi Muhammad
 Email: moh_magdi@acm.org
 */
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<(int)m;i++)
#define REP(i,k,m)      for(int i=k;i<(int)m;i++)
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define OO ((int)1e9)
#define MAX 100000

typedef long long ll;

int diri[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dirj[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int compare(double d1, double d2) {
	if (fabs(d1 - d2) < 1e-9)
		return 0;
	if (d1 < d2)
		return -1;
	return 1;
}
int I, J;
inline bool valid(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

using namespace std;

#define SMALL
#define LARGE
int T;

struct node {
	ll val;
	int ind, steps;
};
set<pair<ll, int> > vis;
int bfs(vector<int> rem, ll val) {
	vis.clear();
	sort(all(rem));
	deque<node> q;
	node n = { val, 0, 0 };
	q.push_back(n);
	while (q.size()) {
		node cur = q.front();
		q.pop_front();
		if (cur.ind == rem.size())
			return cur.steps;
		if (cur.val > rem[cur.ind]) {
			node nn = { cur.val + rem[cur.ind], cur.ind + 1, cur.steps };
			if (!vis.count(mp(nn.val, nn.ind))) {
				vis.insert(mp(nn.val, nn.ind));
				q.push_front(nn);
			}
		} else {
			node nn = { cur.val + (cur.val - 1), cur.ind, cur.steps + 1 };
			if (!vis.count(mp(nn.val, nn.ind))) {
				vis.insert(mp(nn.val, nn.ind));
				q.push_back(nn);
			}
			node nn2 = { cur.val, cur.ind + 1, cur.steps + 1 };
			if (!vis.count(mp(nn2.val, nn2.ind))) {
				vis.insert(mp(nn2.val, nn2.ind));
				q.push_back(nn2);
			}
		}
	}
	return -1;
}

int main() {

	freopen("1.in", "rt", stdin);
#ifdef SMALL
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small.out", "wt", stdout);
#endif
#ifdef LARGE
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
#endif

	cin >> T;
	rep(tt,T) {
		printf("Case #%d: ", tt + 1);
		int v, n, x;
		cin >> v >> n;
		vector<int> rem;
		rep(i,n) {
			cin >> x;
			rem.pb(x);
		}
		sort(all(rem));
		rep(i,n) {
			if (rem[i] < v) {
				v += rem[i];
			} else
				break;
		}
		vector<int> r;
		rep(i,rem.size())
			if (rem[i] >= v)
				r.pb(rem[i]);
		int res = bfs(r, v);
		cout << res << endl;
		cerr << tt << endl;
	}
	return 0;
}
//end


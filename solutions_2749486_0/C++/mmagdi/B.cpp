/*
 TASK:B
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

char dirR[] = { 'E', 'S', 'W', 'N' };
char dirC[] = { 'W', 'N', 'E', 'S' };
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
//#define LARGE
int T;

struct node {
	int x, y, lvl;
	string moves;
};

int main() {
	freopen("1.in", "rt", stdin);
#ifdef SMALL
	freopen("B-small-attempt1.in", "rt", stdin);
	freopen("B-small1.out", "wt", stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
#endif

	cin >> T;
	rep(tt,T) {
		printf("Case #%d: ", tt + 1);
		int x, y;
		cin >> x >> y;
		queue<node> q;
		map<pair<int, int>, bool> vis;
		node str = { 0, 0, 1, "" };
		q.push(str);
		while (q.size()) {
			node cur = q.front();
			q.pop();
			if (mp(cur.x, cur.y) == mp(x, y)) {
				cout << cur.moves << endl;
				break;
			}
			if (vis[mp(cur.x, cur.y)])
				continue;
			vis[mp(cur.x, cur.y)] = 1;
			rep(i,4) {
				int ni = cur.x + diri[i], nj = cur.y + dirj[i];
				node nx = { ni, nj, cur.lvl + 1, cur.moves };
				if (cur.lvl == 1) {
					nx.moves += dirC[i];
				} else {
					nx.moves += dirR[i];
					nx.moves += dirC[i];
				}
				q.push(nx);
			}

		}
		cerr << tt << endl;
	}
	return 0;
}
//end


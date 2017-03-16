#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <complex>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define M 1001
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// N, S, E, W
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
string dir = "NSEW";
int d1, d2;
string res;
map <pair <pi, int>, int> vis;

string bfs() {
	queue<pair<pi, string> > q;
	q.push(mp(mp(0, 0), ""));
	int lvl = 1;
	while (sz(q)) {
		int si = sz(q);
		while (si--) {
			int x = q.front().first.first, y = q.front().first.second;
			string s = q.front().second;
			q.pop();
			FOR (i , 0 , 4) {
				int xx = x + dx[i] * lvl, yy = y + dy[i] * lvl;
				if (vis[mp(mp(xx, yy), lvl)])
					continue;
				vis[mp(mp(xx, yy), lvl)] = 1;
				if (xx == d1 && yy == d2) {
					return s + dir[i];
				}
				q.push(mp(mp(xx, yy), s + dir[i]));
			}
		}
		lvl++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//	freopen("o.txt", "wt", stdout);
#endif
	int t;
	scanf("%d", &t);
	FOR (cs, 1 , t + 1) {
		vis.clear();
		res = "";
		scanf("%d%d", &d1, &d2);
		printf("Case #%d: %s\n", cs, bfs().c_str());
	}
	return 0;
}

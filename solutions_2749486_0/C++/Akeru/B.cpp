#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)
#define dump3(x, y, z) (cout << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", "<< z << ")" << endl)

typedef long long ll;
typedef pair<int, int> pii;

int T;
int gx, gy;

map<pii, int> dist;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char dc[] = { 'N', 'S', 'E', 'W' };

class node {
public:
	int x, y;
	int t;
	string path;

	node(int x, int y, int t, string p):x(x), y(y), t(t), path(p) {}

	bool operator<(const node &r) const {
		return dist[pii(x, y)] > dist[pii(r.x, r.y)];
	}
};

string solve(int sx, int sy)
{
	priority_queue<node> que;

	dist.insert(map<pii, int>::value_type(pii(sx, sy), 0));
	que.push(node(sx, sy, 1, ""));

	while (!que.empty()) {
		node nd = que.top(); que.pop();
		int x = nd.x, y = nd.y;
		if (x == gx && y == gy)
			return nd.path;

		int t = nd.t;
		rep(i, 4) {
			int tx = x+dx[i]*t, ty = y+dy[i]*t;

			int tt = t+1;
			if (dist.find(pii(tx, ty)) == dist.end()) {
				dist.insert(map<pii, int>::value_type(pii(tx, ty), dist[pii(x, y)]+1));
				que.push(node(tx, ty, tt, nd.path+dc[i]));
			}
		}
	}

	return "Error";
}

int main(void)
{
	cin >> T;
	rep(t, T) {
		dist = map<pii, int>();

		cin >> gx >> gy;
		string ret = solve(0, 0);

		printf("Case #%d: %s\n", t+1, ret.c_str());
	}
	return 0;
}

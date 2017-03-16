#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

int N;
string L[1000], R[1000];
vector<int> es[2000];
bool vted[2000];
int match[2000];
int lc, rc;

bool dfs(int v) {
	vted[v] = true;
	REP(i, es[v].size()) {
		int u = es[v][i], w = match[u];
		if (w < 0 || !vted[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int matching() {
	int res = 0;
	REP(i, 2000) match[i] = -1;
	REP(i, lc + rc - 1000) {
		int v = (i < lc) ? i : i - lc + 1000;
		if (match[v] < 0) {
			CLEAR(vted);
			if (dfs(v)) ++res;
		}
	}
	return res;
}

void solve() {
	cin >> N;
	map<string, int> l, r;
	lc = 0; rc = 1000;
	REP(i, N) {
		cin >> L[i] >> R[i];
		if (l.count(L[i]) == 0) l.insert(MP(L[i], lc++));
		if (r.count(R[i]) == 0) r.insert(MP(R[i], rc++));
	}

	CLEAR(es);
	REP(i, N) {
		int li = l[L[i]], ri = r[R[i]];
		es[li].push_back(ri); es[ri].push_back(li);
	}

	cout << (N - (lc + rc - 1000 - matching())) << endl;

	//CLEAR(vted);
	//int cnt = 0;
	//vector<vector<int>> conn;
	//REP(i, lc + rc - 1000) {
	//	int v1 = (i < lc) ? i : i - lc + 1000;
	//	if (vted[v1]) continue;
	//	queue<int> q;
	//	q.push(v1);
	//	conn.push_back();
	//	while (!q.empty()) {
	//		int v = q.front(); q.pop();
	//		vted[v] = true;
	//		conn[conn.size() - 1].push_back(v);
	//		REP(j, es[v].size()) if (!vted[es[v][j]]) q.push(es[v][j]);
	//	}
	//	++cnt;
	//}
	//cerr << "ŽÀÛ‚Ì•Ó‚Ì”: " << N << endl;
	//cerr << "’¸“_”: " << (lc + rc - 1000) << endl;
	//cerr << "˜AŒ‹—Ìˆæ”: " << cnt << endl;
	//cout << (N - (lc + rc - 1000 - cnt)) << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	REP(i, T) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}
	return 0;
}

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
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
#include <ctime>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

string testname = "B-small-attempt1";

const int inf = 1000000000;

int h, n, m;
int a[128][128], b[128][128];
int c[128][128];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main () {
    freopen((testname+".in").c_str(), "r", stdin);
    freopen((testname+".out").c_str(), "w", stdout);
    int t;
    cin >> t;
    FOR (test, 1, t+1) {
	cin >> h >> n >> m;
	REP (i, n) REP (j, m) cin >> b[i][j];
	REP (i, n) REP (j, m) cin >> a[i][j];
	REP (i, n) REP (j, m) c[i][j] = -inf;
	priority_queue<pair<int, pii>, vector<pair<int, pii> > > pq;
	pq.push(make_pair(h, pii(0, 0)));
	c[0][0] = h;
	int H = h;
	while (pq.size()) {
	    int y = pq.top().Y.Y;
	    int x = pq.top().Y.X;
	    int h = pq.top().X;
	    pq.pop();
	    if (c[y][x] != h) continue;
	    REP (dir, 4) {
		int q = y + dy[dir];
		int w = x + dx[dir];
		if (q < 0 || w < 0 || q >= n || w >= m) continue;
		if (0 > b[q][w] - 50 || a[y][x] > b[q][w] - 50 || a[q][w] > b[q][w] - 50 || a[q][w] > b[y][x] - 50) 
		    continue;
		int hh = h;
		if (h > b[q][w] - 50) {
		    hh = b[q][w] - 50;
		}
		int val = hh;
		if (hh != H) {
		    if (hh - a[y][x] < 20)
			val -= 100;
		    else 
			val -= 10;
		}
		if (c[q][w] < val) {
		    c[q][w] = val;
		    pq.push(make_pair(c[q][w], pii (w, q)));
		}
	    }
	}
	printf("Case #%d: %.9lf\n", test, (H-c[n-1][m-1]) / 10.0);
    }
    return 0;
}

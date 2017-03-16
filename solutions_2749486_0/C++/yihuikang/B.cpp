#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string>
#include <cstring>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define repeat(t) for (int asdfg=0; asdfg < (t); asdfg++)
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};
const char z[]={'W','S','N','E'};

int x, y, N;
bool g[1000][1000];
int path[1000][1000];
int main() {
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int cas, qx, qy;
	cin >> cas;
	for (int T=1; T<=cas; T++) {
		cin >> qx >> qy;
		N = 2*max(abs(qx),abs(qy));
		memset(g, 0, sizeof(g));
		g[0][0]=0;
		queue<pii> q[2];
		q[0].push(mp(0,0));
		int moves=0;
		for (int i=1; !g[qx+N][qy+N]; i++) {
			int c=i&1;
			while (!q[c^1].empty()) {
				pii now=q[c^1].front(); q[c^1].pop();
				int x=now.X, y=now.Y;
				// printf("%d || x y : %d %d\n",i,x,y);
				for (int d=0; d<4; d++) {
					int nx=x+dx[d]*i;
					int ny=y+dy[d]*i;
					// printf("nx ny : %d %d\n",nx,ny);
					if (nx<-N || nx > N || ny <-N || ny > N) continue;
					if (g[nx+N][ny+N]) continue;
					g[nx+N][ny+N]=true;
					path[nx+N][ny+N]=d;
					if (nx == qx && ny == qy) { moves=i; break; }
					q[c].push(mp(nx,ny));
				}
			}
		}
		// printf("moves=%d\n",moves);
		string ans;
		for (int x=qx,y=qy; moves; ) {
			ans+=z[path[x+N][y+N]];
			int nx=x-dx[path[x+N][y+N]]*moves;
			int ny=y-dy[path[x+N][y+N]]*moves;
			x=nx, y=ny;
			moves--;
		}
		moves = ans.size();
		cout << "Case #" << T << ": ";
		for (int i=moves-1; i>=0; i--) cout << ans[i];
		cout << endl;
	}
	return 0;
}
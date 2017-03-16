
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int CE[110][110],FL[110][100],D[110][110];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int R,C,H;


int earliest(int r1, int c1, int r2, int c2){
	if(r1 < 0 || r1 == R || c2 <0 || c2 == C)return oo;
	int MC = min(CE[r1][c1], CE[r2][c2]);
	int MF = max(FL[r1][c1], FL[r2][c2]);
	if(MC - 50 < MF)return oo;
	return H - MC + 50;
}
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cin >> H >> R >> C;
		FOR(r,0,R)FOR(c,0,C)cin >> CE[r][c];
		FOR(r,0,R)FOR(c,0,C)cin >> FL[r][c];
		FOR(r,0,R)FOR(c,0,C)D[r][c] = oo;
		D[0][0] = 0;
		{
			queue<pii > q = queue<pii >();
			q.push(pii(0,0));
			while(!q.empty()){
				pii nn = q.front();
				q.pop();
				int r = nn.first;
				int c = nn.second;
				FOR(d,0,4){
					int rr = r + dr[d];
					int cc = c + dc[d];
					if(earliest(r,c,rr,cc)<=0){
						if(D[rr][cc] == oo){
							D[rr][cc] = 0;
							q.push(mp(rr,cc));
						}
					}
				}
			}
		}
		set<pair<int,pii > > q;
		q.clear();
		FOR(r,0,R)FOR(c,0,C)if(D[r][c] == 0)q.insert(mp(0,mp(r,c)));
		while(!q.empty()){
			pii nn = q.begin()->second;
			int r = nn.first;
			int c = nn.second;
			q.erase(q.begin());
			FOR(d,0,4){
				int rr = r + dr[d];
				int cc = c + dc[d];
				int dis = earliest(r,c,rr,cc);
				if(dis == oo)continue;
				dis = max(dis,D[r][c]);
				if(H-dis-FL[r][c] >= 20)dis+=10;
				else dis += 100;
				if(dis<D[rr][cc]){
					if(D[rr][cc] != oo)q.erase(mp(D[rr][cc],mp(rr,cc)));
					D[rr][cc] = dis;
					q.insert(mp(D[rr][cc],mp(rr,cc)));
				}
			}
		}
		printf("Case #%d: %.1lf\n",tcc,0.1*D[R-1][C-1]);
	}
	return 0;
}

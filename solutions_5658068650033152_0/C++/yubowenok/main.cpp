#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int N,M;
int g[25][25];
bool v[25][25];

int dir[4][2] = {-1,0,1,0,0,1,0,-1};
int dfs(int x, int y){
	if(x<0 || y<0 || x>=N || y>=M) return -1;
	if(g[x][y]) return 0;
	if(x==0 || y==0 || x==N-1 || y==M-1) return -1;
	if(v[x][y]) return 0;
	v[x][y] = 1;
	int ans = 1;
	REP(i,0,4){
		int nx = x+dir[i][0], ny = y+dir[i][1];
		int a = dfs(nx, ny);
		if(a==-1) ans = -1;
		else if(ans!=-1) ans += a;
	}
	return ans;
}
int main(){
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		cerr << csn << endl;
		printf("Case #%d: ", csn);
		int K;
		cin >> N >> M >> K;
		int B = N*M;
		int Bmask = 1<<B;
		int ans = B;
		REP(mask,0,Bmask){
			FILL(g,0);
			int cnt = 0;
			REP(b,0,B){
				if((1<<b)&mask){
					g[b/M][b%M] = 1;
					cnt++;
				}
			}
			/*
			if(mask==6438){
				cerr << endl;
				REP(i,0,N){
					REP(j,0,M){
						cerr << g[i][j];
					}
					cerr << endl;
				}
			}
			*/
			FILL(v,0);
			int sol = cnt;
			REP(i,0,N){
				REP(j,0,M){
					if(!g[i][j] && !v[i][j]){
						int a = dfs(i, j);
						if(a!=-1) sol += a;
					}
				}
			}
			if(sol>=K) {
				ans = min(ans, cnt);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
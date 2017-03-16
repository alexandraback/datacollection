#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<set>
#include<cctype>
#include<cassert>
using namespace std;

#ifdef ONLINE_JUDGE

#define assert(x)
#define dbg(x)
#define dbgline()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif
int n,m,H;
const int N = 110;
const int INF = 1000000000; //XXX
int f[N][N];
int c[N][N];
int d[N][N];

int newtime(int f1, int c1, int f2, int c2, int t){
	if(f1>c2-50) return -1;
	if(f2>c2-50) return -1;
	if(f2>c1-50) return -1;
	int wh = H - t;
	if(wh>c2-50){
		int ab = wh - (c2-50);

		wh = c2-50;
		t += ab;
	}
	if(t==0) return 0;
	if(wh-f1>=20) return t+10;
	else return t+100;
}

struct pole{
	int i,j,t;
	pole(int i, int j, int t):i(i),j(j),t(t){}
	bool operator < (const pole& p2) const {
		return t>p2.t;
	}
};

void solve(){
	scanf("%d %d %d",&H,&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d",&c[i][j]);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d",&f[i][j]);
			d[i][j] = INF;
		}
	d[0][0] = 0;
	priority_queue<pole>Q;
	Q.push(pole(0,0,0));
	int res = 0;
	while(!Q.empty()){
		pole p = Q.top(); Q.pop();
		if(p.i==n-1 && p.j==m-1){
			res = p.t;
			break;
		}
		if(p.t!=d[p.i][p.j]) continue;
		for(int i=max(0,p.i-1); i<=min(n-1, p.i+1); i++){
			for(int j=max(0,p.j-1); j<=min(m-1, p.j+1); j++){
				if(abs(p.i-i)+abs(p.j-j)!=1) continue;
				int newt = newtime(f[p.i][p.j], c[p.i][p.j], f[i][j], c[i][j], p.t);
				if(newt!=-1 && newt<d[i][j]){
					d[i][j] = newt;
					Q.push(pole(i,j,newt));
				}
			}
		}
	}
	printf("%.1lf\n",res/10.);
}

int main(){
	int z;
	scanf("%d",&z);
	for(int testc=1; testc<=z; testc++){
		printf("Case #%d: ", testc);
		solve();
	}
}

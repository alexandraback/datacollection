#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=(n-1);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define FORR(i,z,n) for (int (i)=(n-1);(i)>=(z);--(i))
#define FOREACH(it,c) \
  for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(x) remove(unique((x).begin(),(x).end()),(x).end())
#define CLEAR(x,v) memset((x),(v),sizeof((x)))
#define FORS(i,x) for(int i=0;i<(int)(x).size();i++)

typedef long long ll;
typedef vector<ll> VI;
const double EPS=1e-10;
const ll INF=1ll<<61;

ll dp[100][100][10001];
ll f[100][100];
ll c[100][100];
ll seen[100][100];
int n,m,h;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

bool cango(int i, int j, int ii, int jj, int w) {
	if (ii<0||ii>=n||jj<0||jj>=m) return false;
	if (c[ii][jj]-w<50) return false;
	if (c[ii][jj]-f[i][j]<50) return false;
	if (c[ii][jj]-f[ii][jj]<50) return false;
	if (c[i][j]-f[ii][jj]<50) return false;
	return true;
}

ll get(int i, int j, int w) {
	if (w<0) w=0;
	ll& x=dp[i][j][w];
	if (x==-1) {
//		cerr << i << ' ' << j << ' ' << w << endl;
		if (i==n-1&&j==m-1) return x=0;
		x=INF;
		if (w) x=1+get(i,j,w-1);
		int cost;
		if (w>=f[i][j]+20) cost=10;
		else cost=100;
		for (int k=0;k<4;++k) {
			int ii=i+dy[k];
			int jj=j+dx[k];
			if (cango(i,j,ii,jj,w)) x=min(x,cost+get(ii,jj,w-cost));
		}
	}
	return x;
}

void dfs(int i, int j) {
	if (seen[i][j]) return;
	seen[i][j]=true;
	for (int k=0;k<4;++k) {
		int ii=i+dy[k];
		int jj=j+dx[k];
		if (cango(i,j,ii,jj,h)) dfs(ii,jj);
	}
}

int main() {
	int T;
	cin >> T;
	FORE(t,1,T) {
		memset(dp,-1,sizeof(dp));
		memset(seen,0,sizeof(seen));
		cin >> h >> n >> m;
		REP(i,n) REP(j,m) cin >> c[i][j];
		REP(i,n) REP(j,m) cin >> f[i][j];
		dfs(0,0);
		ll mn=INF;
		REP(i,n) REP(j,m) if (seen[i][j]) mn=min(mn,get(i,j,h));
		printf("Case #%d: %.1f\n",t,mn/10.);
	}
}


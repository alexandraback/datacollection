#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

typedef long long ll;

map<ll, ll> f[109][109], g[109][109];
ll best[109][109];

ll N, M, A[109], a[109], B[109], b[109];

ll findBest(int,int);
ll findF(int,int,ll);
ll findG(int,int,ll);

ll findBest(int i, int j) {
	//printf("BEST %d %d\n", i, j);
	if(i+1>N || j+1>M) return 0ll;

	if(best[i][j] != -1) return best[i][j];
	if(A[i+1]!=B[j+1]) return best[i][j]=max(findBest(i+1,j), findBest(i,j+1));
	
	if(a[i+1] > b[j+1]) return best[i][j]=b[j+1]+findF(i+1,j+1,a[i+1]-b[j+1]);
	else if(a[i+1]==b[j+1]) return best[i][j]=a[i+1]+findBest(i+1,j+1);
	else return best[i][j]=a[i+1]+findG(i+1,j+1,b[j+1]-a[i+1]);
}

ll findF(int i, int j, ll x) {
	//printf("F %d %d %lld\n", i, j, x);
	if(j+1>M || i>N) return 0ll;
	if(x==0) return findBest(i,j);

	if(f[i][j].find(x) != f[i][j].end()) return f[i][j][x];
	if(A[i] != B[j+1]) return f[i][j][x]=max(findBest(i,j), findF(i,j+1,x));

	if(x>b[j+1]) return f[i][j][x]=b[j+1]+findF(i,j+1,x-b[j+1]);
	else if(b[j+1]==x) return f[i][j][x]=x+findBest(i,j+1);
	else return f[i][j][x]=x+findG(i,j+1,b[j+1]-x);
}

ll findG(int i, int j, ll x) {
	//printf("G %d %d %lld\n", i,j,x);
	if(i+1>N || j>M) return 0ll;
	if(x==0) return findBest(i,j);
	
	if(g[i][j].find(x) != g[i][j].end()) return g[i][j][x];
	if(A[i+1] != B[j]) return g[i][j][x] = max(findBest(i,j), findG(i+1,j,x));
	
	if(x>a[i+1]) return g[i][j][x]=a[i+1]+findG(i+1,j,x-a[i+1]);
	else if(x==a[i+1]) return g[i][j][x]=x+findBest(i+1,j);
	else return g[i][j][x]=x+findF(i+1,j,a[i+1]-x);
}

int test() {
	int x;
	return x=10+343*2;
}

int main() {
	int T; scanf("%d", &T);
	
	for(int tc=1; tc<=T; tc++) {
		scanf("%d%d", &N, &M);
		for(int i=0; i<=N+1; i++) for(int j=0; j<=M+1; j++) {
			best[i][j]=-1;
			f[i][j].clear();
			g[i][j].clear();
		}
		for(int i=1; i<=N; i++) scanf("%lld%lld", &a[i], &A[i]);
		for(int i=1; i<=M; i++) scanf("%lld%lld", &b[i], &B[i]);
		
		printf("Case #%d: %lld\n", tc, findBest(0,0));
	}

	return 0;
}
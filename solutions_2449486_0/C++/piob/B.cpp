#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

int n, m;
int M[110][110];
int G[110][110];

bool solve(){
	int k;
	FWD(i,0,n)
		FWD(j,0,m)
			G[i][j] = 0;
	FWD(i,0,n){
		k = -1;
		FWD(j,0,m) k = max(k, M[i][j]);
		FWD(j,0,m) G[i][j] |= (k == M[i][j]);
	}
	FWD(j,0,m){
		k = -1;
		FWD(i,0,n) k = max(k, M[i][j]);
		FWD(i,0,n) G[i][j] |= (k == M[i][j]);
	}
	FWD(i,0,n)
		FWD(j,0,m)
			if(!G[i][j])
				return 0;
	return 1;
}

int main(){
	int Z;
	scanf("%d", &Z);
	FWD(z,1,Z+1){
		printf("Case #%d: ", z);
		scanf("%d %d", &n, &m);
		FWD(i,0,n)
			FWD(j,0,m)
				scanf("%d", &M[i][j]);
		printf(solve()?"YES\n":"NO\n");
	}
}


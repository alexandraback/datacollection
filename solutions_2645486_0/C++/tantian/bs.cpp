#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int f[20][20];
int v[10010];
int n,M,R;

void update( int &x, int y ){
	if (y>x) x=y;
}

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d %d %d", &M, &R, &n);
		for (int i=0; i<n; ++i){
			scanf("%d", v+i);
		}
		memset(f,-1,sizeof(f));
		f[0][M]=0;
		for (int i=0; i<n; ++i)
			for (int j=0; j<=M; ++j){
				if (f[i][j]>=0){
					int t=min(j+R,M);
					for (int k=0; k<=t; ++k){
						update(f[i+1][t-k],f[i][j]+v[i]*k);
					}
				}
			}
		printf("Case #%d: %d\n", T, f[n][0]);
	}
}

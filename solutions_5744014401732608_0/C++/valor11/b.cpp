#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 60;
//#define LOACL
ll m,n;
int map[N][N];
ll calc(){
	ll f[N];
	memset(f,0,sizeof(f));
	f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)
			if (map[j][i])
				f[i]+=f[j];
	}
	return f[n];
}

int dfs(int x,int y){
	if (x==n){
		if (m==calc()) return 1;
		return 0;
	}
	int nx,ny;
	nx=x;ny=y+1;
	if (y==n){
		nx=x+1; ny=nx+1;
	}
	if (dfs(nx,ny)) return 1;
	map[x][y]=1;
	if (dfs(nx,ny)) return 1;
	map[x][y]=0;
	return 0;
}


int main(){
	#ifdef LOACL
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	for(int times=1;times<=T;times++){
		cin >> n >> m;
		printf("Case #%d: ",times);
		memset(map,0,sizeof(map));
		if (dfs(1,2)) {
			puts("POSSIBLE");
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) printf("%d",map[i][j]);
				puts("");
			}
		}else puts("IMPOSSIBLE");
	}
	return 0;
}
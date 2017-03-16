#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double db;
int T,cas=0;
int N,X,Y,g[101][101],a,b;
db ans;
inline void dfs(int num,int x,int y){
	if(num==N+1){
		b++;
		if(g[X][Y]) a++;
		return;
	}
	if(y==50||(g[x-1][y-1]&&g[x+1][y-1])){
		g[x][y]=1;dfs(num+1,50,N*2+50);g[x][y]=0;
	}
	else{
		if(!g[x][y-2]&&!g[x-1][y-1]&&!g[x+1][y-1]) dfs(num,x,y-1);
		else{
			if(!g[x-1][y]&&!g[x-1][y-1]&&!g[x-1][y-2]&&!g[x-2][y-1]) dfs(num,x-1,y-1);
			if(!g[x+1][y]&&!g[x+1][y-1]&&!g[x+1][y-2]&&!g[x+2][y-1]) dfs(num,x+1,y-1);
		}
	}
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(g,0,sizeof(g));
		scanf("%d%d%d",&N,&X,&Y);X+=50;Y+=50;
		a=b=0;
		if(X>0&&Y>0&&X<100&&Y<100) dfs(1,50,N*2+50);
		if(b==0) ans=0;
		else ans=(db)a/(db)b;
		printf("Case #%d: ",++cas);
		printf("%lf\n",ans);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool v[111][111];
FILE *of;
int i,j,k,n,m,ans,tests,cc,lim,tot,now,num,ts[111][111];
void dfs(int x,int y){
	num++;ts[x][y]=now;
	if (x>1&&ts[x-1][y]<now&&!v[x-1][y]) dfs(x-1,y);
	if (y>1&&ts[x][y-1]<now&&!v[x][y-1]) dfs(x,y-1);
	if (x<n&&ts[x+1][y]<now&&!v[x+1][y]) dfs(x+1,y);
	if (y<m&&ts[x][y+1]<now&&!v[x][y+1]) dfs(x,y+1);
}
void work(int x,int y,int tmp){
	if (tmp>=ans) return;
	if (y>m) x++,y=1;
	if (x>n){
		num=0;now++;
		for (i=1;i<=m;i++){
			if (!v[1][i]&&ts[1][i]<now) dfs(1,i);
			if (!v[n][i]&&ts[n][i]<now) dfs(n,i);
		}
		for (i=1;i<=n;i++){
			if (!v[i][1]&&ts[i][1]<now) dfs(i,1);
			if (!v[i][m]&&ts[i][m]<now) dfs(i,m);
		}
		if (n*m-num>=lim) ans=tmp;
		return;
	}
	v[x][y]=1;work(x,y+1,tmp+1);v[x][y]=0;
	work(x,y+1,tmp);
}
int main(){
	of=fopen("CS0.out","w");
	scanf("%d",&tests);cc=0;
	while (tests--){
		cc++;printf("%d\n",cc);
		scanf("%d%d%d",&n,&m,&lim);ans=lim;memset(ts,0,sizeof(ts));now=0;memset(v,0,sizeof(v));
		work(1,1,0);
		fprintf(of,"Case #%d: %d\n",cc,ans);
	}
	return 0;
}

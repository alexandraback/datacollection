#include<iostream>
#include<cstdio>
using namespace std;
int f[10002][11],v[10001],n,r,e,t,i;
void init(){
  int i,j;
  scanf("%d%d%d",&e,&r,&n);
  for(i=1;i<=n;i++)
	scanf("%d",&v[i]);
  for(i=0;i<=n+1;i++)
	for(j=0;j<=e;j++)
	  f[i][j]=-2000000000;
  f[0][e]=0;
}
void solve(){
  int i,j,k,ans=0;
  for(i=0;i<=n;i++)
	for(j=0;j<=e;j++)
	  for(k=0;k<=j;k++)
		f[i+1][min(j-k+r,e)]=max(f[i+1][min(j-k+r,e)],f[i][j]+k*v[i]);
  for(j=0;j<=e;j++)
	ans=max(ans,f[n+1][j]);
  printf("%d\n",ans);
}
int main(){
  freopen("2.in","r",stdin);
  freopen("2.out","w",stdout);
  scanf("%d",&t);
  for(i=1;i<=t;i++){
	printf("Case #%d: ",i);
	init();
	solve();
  }
  fclose(stdin);
  fclose(stdout);
  return(0);
}

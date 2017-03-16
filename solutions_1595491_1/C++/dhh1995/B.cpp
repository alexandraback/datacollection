#include<cstdio>
#include<cstring>
int n,m,p,x,f[105][105];
int max(int a,int b){return a>b?a:b;}
int score(int x,int p,int s)
{
	if (s) return x>=p*3-4;
	return x>=p*3-2;
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int test,Case; scanf("%d",&test);
	for (Case=1;Case<=test;Case++){
		scanf("%d%d%d",&n,&m,&p);
		for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) f[i][j]=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			for (int j=0;j<=m;j++){
				f[i][j]=max(f[i][j],f[i-1][j]+score(x,p,0));
				if (j && 2<=x && x<=28) f[i][j]=max(f[i][j],f[i-1][j-1]+score(x,p,1));
				}
			}
		/*for (int i=0;i<=n;i++){
			for (int j=0;j<=m;j++) printf("%d ",f[i][j]);
			printf("\n");}*/
		printf("Case #%d: %d\n",Case,f[n][m]);
		}
	return 0;
}

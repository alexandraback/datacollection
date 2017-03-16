#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N,M,u[105][105],d[105][105],l[105][105],r[105][105],a[105][105];

void init()
{
	scanf("%d%d",&N,&M);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++) scanf("%d",&a[i][j]);
//	for (int i=1; i<=N; i++){
//		for (int j=1; j<=M; j++) cout<<a[i][j]<<' ';cout<<endl;}
	for (int i=1; i<=N; i++)
	{
		l[i][0]=r[i][M+1]=0;
		for (int j=1; j<=M; j++) l[i][j]=max(l[i][j-1],a[i][j]);
		for (int j=M; j; j--) r[i][j]=max(r[i][j+1],a[i][j]);
	}
	for (int i=1; i<=M; i++)
	{
		u[i][0]=d[i][N+1]=0;
		for (int j=1; j<=N; j++) u[i][j]=max(u[i][j-1],a[j][i]);
		for (int j=N; j; j--) d[i][j]=max(d[i][j+1],a[j][i]);
	}
}

bool ok()
{
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++) if ((l[i][j-1]>a[i][j]||r[i][j+1]>a[i][j])&&(u[j][i-1]>a[i][j]||d[j][i+1]>a[i][j])) return 0;
	return 1;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B1.out","w",stdout);
	int T,i;
	for (scanf("%d",&T),i=1; i<=T; i++)
	{
		init();
		printf("Case #%d: %s\n",i,ok()?"YES":"NO");
	}
	return 0;
}

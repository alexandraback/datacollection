#include<iostream>
#include<cstdio>
#define maxn 110
using namespace std;
int tu[maxn][maxn];
int n,m;
bool Check(int x,int y,int sym)
{
	bool ok1=1,ok2=1;
	for(int i=1;i<=n;i++)
		if(tu[i][y]>sym)
			ok1=0;
	for(int i=1;i<=m;i++)
		if(tu[x][i]>sym)
			ok2=0;
	if(ok1==0&&ok2==0)
		return 0;
	else 
		return 1;
}
void Doit()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(Check(i,j,tu[i][j])==0)
			{
				printf("NO\n");
				return ;
			}
	printf("YES\n");
}
int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int k;
	scanf("%d",&k);
	for(int lt=1;lt<=k;lt++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&tu[i][j]);
		printf("Case #%d: ",lt);
		Doit();
	}
	return 0;
}

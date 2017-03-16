#include<stdio.h>
#include<string.h>
int max(int a,int b){return a>b?a:b;}
int main()
{
	freopen("B-small-attempt0.txt","r",stdin);
	freopen("pB_out.txt","w",stdout);
	int t,cas=1;
	int map[102][102],r[102],c[102];
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j,flg=1;
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",&map[i][j]);
				r[i]=max(r[i],map[i][j]);
				c[j]=max(c[j],map[i][j]);
			}
		for(i=0;i<n&&flg;i++)
			for(j=0;j<m&&flg;j++)
				if(map[i][j]<r[i]&&map[i][j]<c[j])flg=0;
		printf("Case #%d: ",cas++);
		if(flg)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

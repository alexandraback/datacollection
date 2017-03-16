# include <cstdio>
# include <algorithm>

using namespace std;

int ar[100][100],maxrow[100],maxcol[100];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);

		int M,N;
		scanf("%d%d",&M,&N);
		for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&ar[i][j]);

		for(int i=0;i<M;i++)
		{
			maxrow[i]=ar[i][0];
			for(int j=1;j<N;j++)
				maxrow[i]=max(maxrow[i],ar[i][j]);
		}
		for(int j=0;j<N;j++)
		{
			maxcol[j]=ar[0][j];
			for(int i=1;i<M;i++)
				maxcol[j]=max(maxcol[j],ar[i][j]);
		}

		bool flag=true;
		for(int i=0;flag&&(i<M);i++)
		for(int j=0;flag&&(j<N);j++)
			if(min(maxrow[i],maxcol[j])>ar[i][j])
				flag=false;

		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

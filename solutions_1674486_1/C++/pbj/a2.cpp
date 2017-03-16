#include <iostream>
#include <cstring>
#define N 1050
#define inf 0x3f
using namespace std;

int dist[N][N],n,m;
void floyd()
{
	int i,j,k;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (dist[i][k]&& dist[k][j])
						dist[i][j]++;

}
int main()
{
//	freopen("d:\\gcj\\a2.in","r",stdin);  
 //   freopen("d:\\gcj\\a2.out","w",stdout);
	int i,j,k,t,tmp;
	bool fg;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		fg=0;
		memset(dist,0,sizeof(dist));
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&m);
			for(k=0;k<m;k++)
			{
				scanf("%d",&tmp);
				dist[j][tmp-1]=1;
			}
		}
	/*	for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
				cout<<dist[j][k]<<" ";
			cout<<endl;
		}
		cout<<endl<<endl;*/
		floyd();
	/*	for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
				cout<<dist[j][k]<<" ";
			cout<<endl;
		}*/
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				if(dist[j][k]>=2)
				{
					fg=1;
					break;
				}
		printf("Case #%d: ",i);
		if(fg)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
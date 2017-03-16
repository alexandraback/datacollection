#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#define INF 987654321
#define EPS 1e-10
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)<(b)?(b):(a))
using namespace std;
/////////////////////////////////////////
#define MAXN 1010
struct node
{
	int x,y;
};
bool vis[MAXN][2];
node p[MAXN];
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B.out","w",stdout);
	int c,ca=1;
	int n,i,now,cnt;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(i=now=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		memset(vis,false,sizeof(vis));
		for(cnt=0;now<n*2;)
		{
			for(i=0;i<n;i++)
			{
				if(!vis[i][1]&&now>=p[i].y)
				{
					if(!vis[i][0])
						now+=2;
					else
						now++;
					vis[i][0]=vis[i][1]=true;
					cnt++;
					break;
				}
			}
			if(i==n)
			{
				for(i=0;i<n;i++)
				{
					if(!vis[i][0]&&now>=p[i].x)
					{
						vis[i][0]=true;
						cnt++;
						now++;
						break;
					}
				}
				if(i==n)
					break;
			}
		}
		if(now==n*2)
			printf("Case #%d: %d\n",ca++,cnt);
		else
			printf("Case #%d: Too Bad\n",ca++);
	}
	return 0;
}
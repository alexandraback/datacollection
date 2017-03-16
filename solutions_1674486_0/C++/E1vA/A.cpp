#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

vector<int> a[1005];
int c[1005];
vector<int> top;
int b[1005][1005];
int n;
int T;

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		top.clear();
		queue<int> Q;
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int all=0;
		for(int i=1;i<=n;i++)
		{
			int m,x;
			scanf("%d",&m);
			a[i].clear();
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				b[i][x]=1;
				a[i].push_back(x);
				c[x]++;
			}
		}
		for(int i=1;i<=n;i++)
			if(!c[i])
				Q.push(i);
		while(!Q.empty())
		{
			int t=Q.front();
			top.push_back(t);
			Q.pop();
			int sz=a[t].size();
			for(int i=0;i<sz;i++)
			{
				int tmp=a[t][i];
				if(--c[tmp]==0)
					Q.push(tmp);
			}
		}
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			for(int j=i+2;j<n;j++)
			{
				for(int k=i+1;k<j;k++)
				{
					b[top[i]][top[j]]+=b[top[i]][top[k]]*b[top[k]][top[j]];
					if(b[top[i]][top[j]]>=2)
					{
						flag=true;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		printf("Case #%d: %s\n",test,flag?"Yes":"No");
	}
	return 0;
}


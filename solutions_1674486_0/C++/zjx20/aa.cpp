#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int N = 1020;

vector<int> edg[N];

void init(int n)
{
	for(int i=0;i<n;i++) 
		edg[i].clear();
}

bool flag[N];

bool bfs(int x)
{
	memset(flag, 0, sizeof(flag));

	flag[x] = true;
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int xx = q.front(); q.pop();
		for(auto it = edg[xx].begin();it!=edg[xx].end();++it)
		{
			if(flag[*it]) return true;
			flag[*it] = true;
			q.push(*it);
		}
	}
	return false;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,ca=0;

	int i,j;
	int n,m;
	int aa;

	scanf("%d: ",&t);
	while(t--)
	{
		printf("Case #%d: ",++ca);

		scanf("%d",&n);
		init(n+1);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&aa);
				edg[i].push_back(aa);
			}
		}

		bool res = false;
		for(i=1;i<=n;i++)
		{
			if(bfs(i)) 
			{res = true; break;}
		}
		if(res) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
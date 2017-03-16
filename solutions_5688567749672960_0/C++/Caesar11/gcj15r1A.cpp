#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#define N 10000010
using namespace std;

char mark[N];
int dis[N];
queue<int>que;

int reverse(int x)
{
	char temp[100];
	sprintf(temp,"%d",x);
	int len = strlen(temp);
	for (int i=0;i<len/2;++i)
		swap(temp[i],temp[len-i-1]);
	return atoi(temp);

}

int main()
{
	int t, ys = 0;

	dis[1] = 1;
	mark[1] = 1;
	que.push(1);
	while(!que.empty())
	{
		int u = que.front();
		que.pop();

		int v = u + 1;
		if (v < N && mark[v] == 0)
		{
			mark[v] = 1;
			dis[v] = dis[u] + 1;
			que.push(v);
		}

		v = reverse(u);
		if (v < N && mark[v] == 0)
		{
			mark[v] = 1;
			dis[v] = dis[u] + 1;
			que.push(v);
		}
	}

	printf("done\n");

	freopen("A-small-attempt0.in","r",stdin);
	freopen("dataA.out","w",stdout);

	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n",++ys,dis[n]);
	}

	return 0;

}
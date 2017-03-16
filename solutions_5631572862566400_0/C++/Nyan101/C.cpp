#include <stdio.h>
#include <vector>

using namespace std;

int N;
int graph[1002];
int len[1002];
int typ[1002];
int invlen[1002];

bool check[1002];
int maxlen;


void DFS(int v, int curlen);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	int v, l;

	scanf("%d", &T);
	for(int test_case=1;test_case<=T;test_case++)
	{
		scanf("%d ", &N);
		for(int i=1;i<=N;i++)
		{
			scanf("%d ", &graph[i]);
			invlen[i] = 0;
			check[i] = false;
		}

		for(int i=1;i<=N;i++)
		{
			v = i;
			l = 1;
			for(int j=1;j<=N;j++)
				check[j] = false;

			while(1)
			{
				check[v] = true;
				if(graph[v]==i)
				{
					typ[i] = 0;
					len[i] = l;
					break;
				}
				else if(graph[graph[v]]==v)
				{
					typ[i] = graph[v];
					len[i] = l+1;
					break;
				}
				else if(check[graph[v]]==true)
				{
					typ[i] = -1;
					len[i] = 0;
					break;
				}
				v = graph[v];
				l++;
			}
		}

		maxlen = 0;
		for(int i=1;i<=N;i++)
		{
			if(typ[i]>0)
			{
				if(invlen[typ[i]] < len[i])
					invlen[typ[i]] = len[i];
			}
			else if(typ[i]==0 && maxlen < len[i])
				maxlen = len[i];
		}

		int cnt = 0;
		int sumlen = 0;
		for(int i=1;i<=N;i++)
		{
			if(invlen[i]>0)
			{
				sumlen += invlen[i] - 1;
			}
		}

		if(maxlen < sumlen)
			maxlen = sumlen;

		printf("Case #%d: %d\n", test_case, maxlen);

	}

	return 0;
}

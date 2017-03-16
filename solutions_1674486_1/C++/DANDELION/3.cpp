#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool ha[1510];
int n;
vector  < vector < int > > E;
queue < int > Q;
bool judge(int st)
{
	memset(ha, 0, sizeof(ha));
	while(!Q.empty())
		Q.pop();
	Q.push(st);
	ha[st] = 1;
	while(!Q.empty())
	{
		int cre = Q.front();
		Q.pop();
		for(int i = 0; i < E[cre].size(); i++)
		{
			int p = E[cre][i];
			if (ha[p])
				return true;
			ha[p] = true;
			Q.push(p);
		}
	}
	return false;
}
int main()
{
	freopen("A-large (1).in", "r", stdin);
	freopen("222.out" ,"w", stdout);
	int cas, i, sum1;
	scanf("%d", &cas);
	for (int t = 1; t <= cas; t++)
	{
		E.clear();
		scanf("%d", &n);
		E.resize(n + 1);
		for(i = 1; i <= n; i++)
		{
			int k;
			scanf("%d", &k);
			while(k--)
			{
				int p;
				scanf("%d", &p);
				E[i].push_back(p);
			}
		}
		for(i = 1; i <= n; i++)
		{
			if (judge(i))
			{
				break;
			}
		}
		if (i == n + 1)
			printf("Case #%d: No\n", t);
		else
			printf("Case #%d: Yes\n", t);
		
	}
}
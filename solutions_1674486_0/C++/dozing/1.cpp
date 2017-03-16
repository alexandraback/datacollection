#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

using namespace std;

bool flag1[1001];
bool flag;
vector<vector<int> > p;
void dfs(int s)
{
	if(flag)
	{
		return;
	}
	int i;
	for (i = 0; i < p[s].size(); ++i)
	{
		if (flag1[p[s][i]] == 1)
		{
			flag = 1;
			return;
		}
		flag1[p[s][i]] = 1;
		dfs(p[s][i]);
		if(flag)
			return;
	}
}
int main()
{
	int T,N;
	int i,j,k,M;
	int a;
	
	vector<int> v;
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	scanf( "%d\n", &T );
	for(i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);
		scanf( "%d", &N );
		p.clear();
		memset(flag1,0,sizeof(flag1));
		flag = 0;
		
		for (j = 0; j < N; ++j)
		{
			v.clear();
			scanf("%d", &M);
			for (k = 0; k < M; ++k)
			{
				scanf("%d", &a);
				v.push_back(a-1);
			}
			p.push_back(v);
		}
		for (j = 0; j < N; ++j)
		{
			if(!flag1[j])
			{
				memset(flag1,0,sizeof(flag1));
				dfs(j);
				if (flag)
				{
					printf("Yes\n");
					break;
				}
			}
		}
		
		if (!flag)
		{
			printf("No\n");
		}
	}
	return 0;
}
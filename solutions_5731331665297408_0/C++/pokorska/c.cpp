#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

const int MAXN = 10;
std::vector<int> graph[MAXN];
int t,n,m;
int post[MAXN],getNorm[MAXN],getNew[MAXN],perm[MAXN];

bool comp(int a, int b)
{
	return post[a] < post[b];
}

void init()
{
	for(int i = 1; i <= n; ++i)
	{
		getNorm[i] = i;
		perm[i] = i;
	}
	for(int i = 0; i < MAXN; ++i)
		graph[i].clear();
}

bool hasNeigh(int a, int b)
{
	for(int i = 0; i < graph[a].size(); ++i)
		if(graph[a][i] == b) return true;
	return false;
}

bool possible()
{
	//printf("possible?\n");
	std::stack<int> stack;
	stack.push(perm[1]);
	//printf("push %d\n", getNorm[perm[1]]);

	for(int i = 2; i <= n; ++i)
	{
		while(!stack.empty())
		{
			int x = getNorm[stack.top()];
			if(hasNeigh(x,getNorm[perm[i]]))
			{
				//printf("push %d\n", getNorm[perm[i]]);
				stack.push(perm[i]);
				break;
			}
			//printf("pop\n");
			stack.pop();
		}

		if(stack.empty()) return false;
	}

	return true;
}

int main()
{
	scanf("%d", &t);
	for(int test = 1; test <= t; ++test)
	{
		scanf("%d%d", &n, &m);
		init();
		for(int i = 1; i <= n; ++i)
			scanf("%d", &post[i]);
		for(int i = 0; i < m; ++i)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		std::sort(getNorm+1,getNorm+n+1,comp);
		for(int i = 1; i <= n; ++i)
			getNew[getNorm[i]] = i;
/*
		for(int i = 1; i <= n; ++i)
			printf("%d ",post[getNorm[i]]);
		printf("\n");
*/
		printf("Case #%d: ", test);
		do
		{
			if(possible())
			{
				for(int i = 1; i <= n; ++i)
					printf("%d", post[getNorm[perm[i]]]);
				printf("\n");
				break;
			}
		} while(std::next_permutation(perm+1,perm+n+1));
	}
}

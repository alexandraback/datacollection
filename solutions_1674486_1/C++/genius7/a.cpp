#include <cstdio>
using namespace std;
int edges[2000][20];
int parent[2000];
int N;

bool dfs(int cv, int sv)
{
    if(parent[cv] == sv)
	return true;
    parent[cv] = sv;
    for(int i = 1; i <= edges[cv][0]; i++)
    {
	if(dfs(edges[cv][i], sv))
	    return true;
    }
    return false;
}

int main()
{
    int t, i, j, I;
    scanf("%d", &t);
    for(I = 1; I <= t; I ++)
    {
	scanf("%d", &N);
	printf("Case #%d: ", I);
	
	for(i = 1; i <= N; i ++)
	{
	    scanf("%d", &edges[i][0]);
	    for(int j = 1; j <= edges[i][0]; j++)
		scanf("%d", &edges[i][j]);
	}

	for(i = 1; i <= N; i ++)
	    parent[i] = -1;

	for(i = 1; i <= N; i ++)
	{
	    if(dfs(i, i))
	    {
		break;
	    }
	}

	if(i <= N)
	    printf("Yes\n");
	else
	    printf("No\n");
    }
    return 0;
}

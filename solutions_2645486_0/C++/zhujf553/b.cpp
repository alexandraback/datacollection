#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int E, R, N, best;
int a[10000];

void dfs(int i, int s, int e)
{
	
	if(i > N) 
	{
		if(s > best) best = s;
		return ;
	}
	for(int k = 0 ; k <= e ; k++)
	{
		dfs(i + 1, s + k * a[i], e - k + R > E ? E : e - k + R);
	}
}

int main()
{
	int T;
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &T);
	for(int tt = 1 ; tt <= T ; tt++)
	{
		scanf("%d%d%d", &E, &R, &N);
		for(int i = 1 ; i <= N ; i++)
			scanf("%d", &a[i]);
		best = 0;
		dfs(1, 0, E);
		printf("Case #%d: %d\n", tt, best);
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define read(a) scanf("%d", &(a))

int n;
int vis[15];

bool check(int k)
{
	while (k)
	{
		int tmp = k % 10;
		vis[tmp] = 1;
		k /= 10;
	}
	for (int i = 0; i <=9; ++ i)	if (vis[i] == 0)	return false;
	return true;
}

void init()
{
	memset(vis, 0, sizeof(vis));
	read(n);
	if (n == 0)
	{
		printf("INSOMNIA\n");
		return ;
	}
	for (int i = 1; i <= 10000000; ++ i)
	{
		if (check(i * n))
		{
			printf("%d\n", i * n);
			return;
		}
	}
	printf("INSOMNIA\n");
}


int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int sb;
	read(sb);
	for (int i = 1; i <= sb; ++ i)
	{
		printf("Case #%d: ", i);
		init();
		//doit();
	}
	return 0;
}

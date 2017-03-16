#include <bits/stdc++.h>
using namespace std;
int n;
bool f[2501];

int main()
{
	int test;scanf("%d" , &test);
	for(int tt = 1 ; tt <= test ; tt++)
	{
		scanf("%d" , &n);
		memset(f , 0 , sizeof f);
		for(int i = 1 ; i <= 2 * n - 1 ; i++)
			for(int j = 1 ; j <= n ; j++)
			{
				int v;scanf("%d" , &v);
				f[v] ^= 1;
			}
		printf("Case #%d:" , tt);
		for(int i = 1 ; i <= 2500 ; i++)
			if(f[i])
				printf(" %d" , i);
		printf("\n");
	}
	return 0;
}
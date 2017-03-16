#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	int T, zzz = 0;
	scanf("%d", &T);
	while (T --)
	{
		int n;
		scanf("%d", &n);
		map<int, int> M;
		for (int i = 1; i < 2 * n; ++ i)
		{
			for (int j = 1; j <= n; ++ j)
			{
				int x;
				scanf("%d", &x);
				M[x] = M[x] ^ 1;
			}
		}
		printf("Case #%d:", ++ zzz);
		for (auto i : M) if (i.second) printf(" %d", i.first);
		puts("");
	}
}


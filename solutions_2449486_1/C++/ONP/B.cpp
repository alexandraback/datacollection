#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 105;

int n, m;
int current[maxn][maxn], target[maxn][maxn];

int main()
{
	int T, caseNum = 1;
	for (scanf("%d", &T);T --;)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < m; ++ j)
			{
				scanf("%d", &target[i][j]);
				current[i][j] = 1000000000;
			}
		}
		
		for (int iter = 0; iter < n + m; ++iter)
		{
			for (int i = 0; i < n; ++ i)
			{
				int maximum = 0;
				for (int j = 0; j < m; ++ j)
				{
					maximum = max(maximum, target[i][j]);
				}
				for (int j = 0; j < m; ++ j)
				{
					current[i][j] = min(current[i][j], maximum);
				}
			}
			
			for (int j = 0; j < m; ++ j)
			{
				int maximum = 0;
				for (int i = 0; i < n; ++ i)
				{
					maximum = max(maximum, target[i][j]);
				}
				for (int i = 0; i < n; ++ i)
				{
					current[i][j] = min(current[i][j], maximum);
				}
			}
		}
		
		bool valid=true;
		for (int i = 0; i < n; ++ i)
		{
			for (int j = 0; j < m; ++ j)
			{
				if (current[i][j] != target[i][j])
				{
					valid=false;
				}
			}
		}
		
		printf("Case #%d: %s\n",caseNum++,valid?"YES":"NO");
	}
	return 0;
}

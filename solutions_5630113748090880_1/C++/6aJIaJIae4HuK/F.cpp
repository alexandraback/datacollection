#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int nums[110][60];
int cnt[2501];

int main()
{
	freopen("B-large (1).in", "r", stdin);
	freopen("B-large (1).out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		int n;
		scanf("%d", &n);
		
		memset(cnt, 0, 2501 * 4);

		for (int i = 0; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &nums[i][j]);
				cnt[nums[i][j]]++;
			}
		}

		printf("Case #%d: ", test);

		for (int i = 1; i <= 2500; i++)
		{
			if (cnt[i] % 2 == 1)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
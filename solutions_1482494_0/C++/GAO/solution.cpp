#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

const int N = 1010;
int level[N][2];
bool bComplete[N][2];
int ans = -1;

void dfs(int n, int star, int count, int depth);

int solve()
{
	ans = -1;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &level[i][0], &level[i][1]);
		bComplete[i][0] = bComplete[i][1] = false;
	}

	dfs(n, 0, 0, 0);

	return ans;
}

void dfs(int n, int star, int count, int depth)
{
	if (count == n)
	{
		if (ans == -1 || depth < ans)
		{
			ans = depth;
		}
		return;
	}

	if (ans != -1)
	{
		if (depth + n - count >= ans)
			return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (!bComplete[i][0] && !bComplete[i][1])
		{
			if (star >= level[i][0])
			{
				bComplete[i][0] = true;
				dfs(n, star+1, count, depth+1);
				bComplete[i][0] = false;
			}

			if (star >= level[i][1])
			{
				bComplete[i][1] = true;
				dfs(n, star+2, count+1, depth+1);
				bComplete[i][1] = false;
			}
			
		}
		else if (bComplete[i][0] && !bComplete[i][1])
		{
			if (star >= level[i][1])
			{
				bComplete[i][1] = true;
				dfs(n, star+1, count+1, depth+1);
				bComplete[i][1] = false;
			}
		}
	}
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int caseNum;
	scanf("%d", &caseNum);

	for (int caseId = 1; caseId <= caseNum; ++caseId)
	{
		printf("Case #%d: ", caseId);

		solve();

		if (ans == -1)
			printf("Too Bad\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}
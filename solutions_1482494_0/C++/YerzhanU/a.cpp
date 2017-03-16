#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define MAXN 1001

int n;
int a[MAXN][2];
bool mark[MAXN][2];
int cur;
int passed;
int ans;

inline int get(int j)
{
	for (int i = 0; i < n; ++i)
		if (!mark[i][j] && cur >= a[i][j])
			return j;
	return -1;
}

inline void solve(int test_case)
{
	cur = 0;
	passed = 0;
	ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i][0], &a[i][1]);
	while(passed < n)
	{
		int t = get(1);
		if (t != -1)
		{
			mark[t][1] = 1;
			cur += 2;
			++passed;
			++ans;
			continue;
		}
		t = get(0);
		if (t != -1)
		{
			mark[t][0] = 1;
			cur += 1;
			++ans;
			continue;
		}
		break;
	}
	if (passed == n)
		printf("Case #%d: %d\n", test_case + 1, ans);
	else
		printf("Case #%d: %s\n", test_case + 1, "Too Bad");
}

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	for (int test_case = 0; test_case < test_cases; ++test_case)
	{
		memset(mark, 0, sizeof(mark));
		solve(test_case);
	}
	return 0;
}

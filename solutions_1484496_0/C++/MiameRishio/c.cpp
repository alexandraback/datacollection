#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int n, sum;
long long a[500];
long long m1[500];
long long m2[500];
int e1, e2;
bool found;
void dfs(int depth, long long ans)
{
	if (found)
		return;
	if (e1 > 0 && e2 > 0 && ans == 0)
	{
		found = true;
		for (int i = 0; i < e1; i++)
			printf("%lld ", m1[i]);
		printf("\n");
		for (int i = 0; i < e2; i++)
			printf("%lld ", m2[i]);
		printf("\n");
		return;
	}
	if (depth == n)
		return;
	m1[e1] = a[depth];
	e1++;
	dfs(depth + 1, ans + a[depth]);
	e1--;

	m2[e2] = a[depth];
	e2++;
	dfs(depth + 1, ans - a[depth]);
	e2--;

	dfs(depth + 1, ans);
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int testCase;
	scanf ("%d", &testCase);
	for (int t = 1; t <= testCase; t++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		found = false;
		e1 = 0;
		e2 = 0;
		printf("Case #%d: \n", t);
		dfs(0, 0);
	}
	return 0;
}
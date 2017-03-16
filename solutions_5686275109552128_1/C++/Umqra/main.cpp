#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = (int)1e4;
const int INF = (int)1e9;
int cnt[N];

void solve(int testId)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &cnt[i]);
	int maxP = *max_element(cnt, cnt + n);
	int minTime = maxP;
	for (int i = 1; i <= maxP; i++)
	{
		int curTime = i;
		for (int s = 0; s < n; s++)
			curTime += (cnt[s] + i - 1) / i - 1;
		minTime = min(minTime, curTime);
	}
	printf("Case #%d: %d\n", testId, minTime);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
	return 0;
}

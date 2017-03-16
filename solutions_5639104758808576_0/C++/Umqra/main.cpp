#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int N = (int)2e3;

void solve(int testId)
{
	int n;
	string str;
	cin >> n >> str;
	int cnt = str[0] - '0';
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int delta = max(0, i - cnt);
		ans += delta;
		cnt += str[i] - '0' + delta;
	}
	printf("Case #%d: %d\n", testId, ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
	return 0;
}

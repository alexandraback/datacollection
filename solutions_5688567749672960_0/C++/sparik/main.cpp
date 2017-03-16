#pragma comment (linker,"/STACK:256000000")
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

#define INF 1000000000
#define lint long long
#define pb push_back
#define MOD 1000000007
#define mp make_pair

int d[1000005];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	queue <int> q;
	q.push(1);
	d[1] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur + 1 <= 1000000 && d[cur + 1] == 0)
		{
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
		long long revnum = 0;
		int num = cur;
		while (num)
		{
			revnum = revnum * 10 + num % 10;
			num /= 10;
		}
		if (revnum <= 1000000 && d[revnum] == 0)
		{
			d[revnum] = d[cur] + 1;
			q.push(revnum);
		}
	}
	int tc, T=1;
	scanf("%d", &tc);
	while (tc--)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", T++, d[n]);
	}
	return 0;
}
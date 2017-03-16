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

/*
int d[26];
string kb, tg;
double ans;
char str[20];
int k, s, l;
int mx;
*/

int main()
{
	freopen("input1s.txt", "r", stdin);
	freopen("output1s.txt", "w", stdout);
	int tc, T = 1;
	scanf("%d", &tc);
	while (tc--)
	{
		/*
		int i, j;
		scanf("%d %d %d", &k, &l, &s);
		cin >> kb;
		cin >> tg;
		for (i = 0; i < 26; ++i)
		{
			d[i] = 0;
		}
		for (i = 0; i < k; ++i)
		{
			d[kb[i] - 'A'] = 1;
		}
		int ok = 1;
		for (i = 0; i < l; ++i)
		{
			if (d[tg[i] - 'A'] == 0)
			{
				ok = 0;
			}
		}
		if (!ok)
		{
			printf("Case #%d: %lf\n", T++, 0.000000);
			continue;
		}
		mx = 0;
		ans = 0;
		rec(0, 1.0, 0);
		ans = (double)mx - ans;
		*/
		int r, c, w;
		scanf("%d %d %d", &r, &c, &w);
		int ans = 0;
		ans += r*(c / w);
		if (c%w != 0)
			ans++;
		ans += w - 1;
		printf("Case #%d: %d\n", T++, ans);


		//printf("Case #%d: %lf\n", T++, ans);
	}
	return 0;
}
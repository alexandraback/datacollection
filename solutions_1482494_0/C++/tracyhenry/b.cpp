#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

pair<int, int> C[10101], S[10101];
int u[10101], N;

void work(int &cur)
{
	for (int i = 1; i <= N; i ++)
		if (u[S[i].second] < 2 && cur >= S[i].first)
		{
			cur += 2 - u[S[i].second];
			u[S[i].second] = 2;
		}
}	

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		int cur = 0, ans = 1000000, MAX = 0;
		cin >> N;

		for (int i = 1; i <= N; i ++)
			cin >> C[i].first >> C[i].second, MAX = max(MAX, C[i].second);
		for (int i = 1; i <= N; i ++)
			C[i].second *= -1;
		sort(C + 1, C + 1 + N);
		for (int i = 1; i <= N; i ++)
			C[i].second *= -1;
		for (int i = 1; i <= N; i ++)
			S[i].first = C[i].second, S[i].second = i;
		sort(S + 1, S + 1 + N);
		//
		for (int mask = 0; mask < (1 << N); mask ++)
		{
			int Bit = 0;
			for (int i = 1; i <= N; i ++)
				if (mask & (1 << (i - 1)))
					Bit ++;
			memset(u, 0, sizeof(u));
			cur = 0;
			work(cur);
			for (int i = 1; i <= N; i ++)
				if (! u[i] && (mask & (1 << (i - 1))))
				{
					if (cur < C[i].first) break;
					u[i] = 1;
					cur ++;
					work(cur);
				}
			if (cur >= MAX)
				ans = min(ans, Bit + N);
		}
		if (ans == 1000000)
		{
			cout << "Too Bad" << endl;
			continue;
		}
		else cout << ans << endl;
	}
	return 0;
}

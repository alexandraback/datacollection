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
    freopen("b.out", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		int cur = 0, ans = -1, L = 0, MAX = 0;
		cin >> N;

		for (int i = 1; i <= N; i ++)
			cin >> C[i].first >> C[i].second, MAX = max(MAX, C[i].second);
		for (int i = 1; i <= N; i ++)
			S[i].first = C[i].second, S[i].second = i;
		sort(S + 1, S + 1 + N);
		memset(u, 0, sizeof(u));
		//
		work(cur);
		if (cur >= MAX)
		{
			cout << L + N << endl;
			continue;
		}
		for ( ; ; )
		{
			int index = -1;
			for (int i = 1; i <= N; i ++)
				if (! u[i] && cur >= C[i].first && (index == -1 || C[i].second > C[index].second))
					index = i;
			if (index == -1) break;
			u[index] = 1;
			cur ++; L ++;
			work(cur);
			if (cur >= MAX)
			{
				ans = 1; break;
			}
		}
		if (ans == -1)
		{
			cout << "Too Bad" << endl;
			continue;
		}
		cout << L + N << endl;
	}
	return 0;
}

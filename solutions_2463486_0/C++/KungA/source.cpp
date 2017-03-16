#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

#define LL long long

set<LL> S;
LL a[1000000];
int n = 0;
LL D;

LL Reverse(LL x)
{
	D = 1;
	LL r = 0;
	while (x > 0)
	{
		r = r * 10 + x % 10;
		x /= 10;
		D *= 10;
	}
	return r;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	for (LL i = 1; i < 1e7; i++)
	{
		LL x = Reverse(i);
		x = i * D + x;
		LL sq = x * x;
		if (sq == Reverse(sq))
			S.insert(x);

		x = Reverse(i / 10);
		x = i * D + x;
		sq = x * x;
		if (sq == Reverse(sq))
			S.insert(x);
	}

	for (set<LL>::iterator it = S.begin(); it != S.end(); it++)
		a[n++] = (*it);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		LL l, r, ans = 0;
		cin >> l >> r;
		for (int i = 0; i < n; i++)
			if (l <= a[i] * a[i] && a[i] * a[i] <= r)
				ans++;

		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
}

































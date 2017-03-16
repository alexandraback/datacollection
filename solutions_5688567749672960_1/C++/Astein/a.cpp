#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int table[10000005];
vector<long long> v;
vector<long long> vv;

void init()
{
	queue<pair<int, int>> Q;
	Q.push({ 1, 1 });
	table[1] = 1;

	while (!Q.empty())
	{
		pair<int, int> now = Q.front(); Q.pop();
		if (now.first + 1 <= 10000000 && table[now.first + 1] == 0)
		{
			Q.push({ now.first + 1, now.second + 1 });
			table[now.first + 1] = now.second + 1;
		}
		int rev = 0, asc = now.first;
		while (asc)
		{
			rev = rev * 10 + (asc % 10);
			asc /= 10;
		}
		if (rev <= 10000000 && table[rev] == 0)
		{
			vv.push_back(now.first);
			Q.push({ rev, now.second + 1 });
			table[rev] = now.second + 1;
		}
	}
	return;
}

long long go(long long n)
{
	long long ret = 0;
	while (v[0] <= n)
	{
		int pos = upper_bound(v.begin(), v.end(), n) - v.begin() - 1;
		long long nn = v[pos];
		ret += (n - nn);
		long long rev = 0, asc = nn;
		while (asc)
		{
			rev = rev * 10 + (asc % 10);
			asc /= 10;
		}
		ret++;
		n = rev;
	}
	return ret + n;
}

int main()
{
//	init();

	for (long long t = 1, i = 10; t < 14; t++, i = i * 10)
	{
		if (t % 2 == 1)
		{
			for (long long j = 0; j * j < i * 10; ++j)
			{
				if (j % 10 == 0) continue;
				long long rev = 0, asc = i + j;
				while (asc)
				{
					rev = rev * 10 + (asc % 10);
					asc /= 10;
				}
				if (i + j < rev) v.push_back(rev);
			}
		}
		else
		{
			for (long long j = 0; j * j < i * 100; ++j)
			{
				if (j % 10 == 0) continue;
				long long rev = 0, asc = i + j;
				while (asc)
				{
					rev = rev * 10 + (asc % 10);
					asc /= 10;
				}
				if (i + j < rev) v.push_back(rev);
			}
		}
	}

	sort(v.begin(), v.end());
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		long long n;
		cin >> n;
		cout << "Case #" << cn << ": " << go(n) << endl;
		//printf("Case #%d: ", cn);
	}
}
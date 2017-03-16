#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;


long long flip(long long n)
{
	long long res = 0;
	while (n > 0)
	{
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	return res;
}

int len(long long n)
{
	int res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return res;
}

int a[20000005];
long long pw[18] = { 0 };

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	pw[0] = 1;
	for (int i = 1; i < 18; i++)
		pw[i] = pw[i-1] * 10;

	int TT;
	scanf("%d", &TT);
	for (int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
		long long n;
		scanf("%lld", &n);
		long long res = 0;
		/*
		queue<int> q;
		memset(a, -1, sizeof(a));
		a[1] = 1;
		q.push(1);
		while (!q.empty())
		{
			int c = q.front();
			q.pop();
			if (c == n)
				break;
			if (a[c + 1] == -1)
			{
				a[c + 1] = c;
				q.push(c+1);
			}
			int rev = flip(c);
			if (a[rev] == -1)
			{
				a[rev] = c;
				q.push(rev);
			}
		}
		long long tm = n;
		while (n > 1)
		{ 
			//printf("%d\n", n);
			n = a[n];
			res++;
		}
		printf("%d ", res+1);
		n = tm;
		res = 0;
		*/
		while (n > 0)
		{
			if (n % 10 == 0)
				res++, n--;
			if (n < 10)
			{
				res += n;
				break;
			}
			int l = len(n);
			long long t = n - n % pw[(l / 2)] + 1;
			res += n - t + 1;
			n = t;
			t = flip(n);
			if (t == n)
			{
				res += n % pw[l / 2 + l % 2] - 1;
				n = n - n % pw[l / 2 + l % 2];
			}
			else
				n = t;
		}
		printf("%lld\n", res);
	}

	return 0;
}
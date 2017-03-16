#include <bits/stdc++.h>

using namespace std;

char a[21], b[21];
char ra[21], rb[21];
string sa, sb;
long long ans;
void solve(int pos, int up, long long p, long long q)
{
	if(a[pos] == 0)
	{
		if(ans > llabs(p - q))
		{
			ans = llabs(p - q);
			sa = ra;
			sb = rb;
		}
		else if(ans == llabs(p - q))
		{
			if(sa > ra || (sa == ra && sb > rb))
			{
				sa = ra;
				sb = rb;
			}
		}
		return;
	}

	long long ans = 1LL << 62;
	if(a[pos] != '?' && b[pos] != '?')
	{
		ra[pos] = a[pos];
		rb[pos] = b[pos];
		return solve(pos + 1, up, p * 10 + a[pos] - '0', q * 10 + b[pos] - '0');
	}

	if(a[pos] == '?' && b[pos] == '?')
	{
		if(up == 3)
		{
			ra[pos] = '9', rb[pos] = '0';
			return solve(pos + 1, up, p * 10 + 9, q * 10);
		}
		else if(up == -3)
		{
			ra[pos] = '0', rb[pos] = '9';
			return solve(pos + 1, up, p * 10, q * 10 + 9);
		}
		else
			for(int i=0; i < 10; i++)
				for(int j=0; j < 10; j++)
				{
					ra[pos] = i + '0';
					rb[pos] = j + '0';
					solve(pos + 1, i > j?-1: i < j? 1: 0, p * 10 + i, q * 10 + j);
				}
		return;
	}

	if(a[pos] == '?')
	{
		rb[pos] = b[pos];
		if(up == 3)
		{
			ra[pos] = '9';
			return solve(pos + 1, up, p * 10 + 9, q * 10 + b[pos] - '0');
		}
		if(up == -3)
		{
			ra[pos] = '0';
			return solve(pos + 1, up, p * 10, q * 10 + b[pos] - '0');
		}

		for(int i=0; i < 10; i++)
		{
			ra[pos] = i + '0';
			solve(pos + 1, ra[pos] < rb[pos]?1: ra[pos] > rb[pos]?-1: 0, p * 10 + i, q * 10 + rb[pos] - '0');
		}
		return;
	}
	ra[pos] = a[pos];
	if(up == 3)
	{
		rb[pos] = '0';
		return solve(pos + 1, up, p * 10 + ra[pos] - '0', q * 10);
	}
	if(up == -3)
	{
		rb[pos] = '9';
		return solve(pos + 1, up, p * 10 + ra[pos] - '0', q * 10 + 9);
	}

	for(int i=0; i < 10; i++)
	{
		rb[pos] = i + '0';
		solve(pos + 1, ra[pos] < rb[pos]?1: ra[pos] > rb[pos]?-1: 0, p * 10 + ra[pos] - '0', q * 10 + i);
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		
		scanf("%s%s", a, b);
		memset(ra, 0, sizeof(ra));
		memset(rb, 0, sizeof(rb));
		ans = 1LL << 62;
		solve(0, 0, 0, 0);
		printf("Case #%d: %s %s\n", tc, sa.c_str(), sb.c_str());
	}
	return 0;
}
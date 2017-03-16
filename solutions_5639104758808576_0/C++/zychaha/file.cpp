#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int Smax;
char seq[2000];

int dg(char c)
{
	return c - '0';
}

int solve()
{
	cin >> Smax >> seq;
	int ret = 0, cnt = 0;
	for (int i = 0; i <= Smax; ++i)
	{
		if (cnt < i)
		{
			ret += i - cnt;
			cnt = i;
		}
		cnt += dg(seq[i]);
	}
	return ret;
}

int main()
{
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		printf("Case #%d: %d\n", case_num, solve());
	}
	
	return 0;
}


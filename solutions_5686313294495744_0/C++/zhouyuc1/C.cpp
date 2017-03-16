#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int N;
string fir[18], sec[18];

int count(size_t num)
{
	int ret = 0;
	while (num != 0)
	{
		if (num & 1)
			++ret;
		num >>= 1;
	}
	return ret;
}

void read_data()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> fir[i] >> sec[i];
}

int solve() // 0 true 1 fake
{
	int ret = 0;
	size_t ULIM = (1<<N);
	size_t num, i, j, k;
	for (num = 0; num < ULIM; ++num)
	{
		int flag = 1;
		// check every fake
		for (k = 0; k < N; ++k)
			if (num & (1<<k)) // specific fake
			{
				int flag1 = 0;
				int flag2 = 0;
				// flag1
				for (i = 0; i < N; ++i)
					if ((num & (1<<i)) == 0)
						if (fir[k] == fir[i])
						{
							flag1 = 1;
							break;
						}
				// flag2
				for (i = 0; i < N; ++i)
					if ((num & (1<<i)) == 0)
						if (sec[k] == sec[i])
						{
							flag2 = 1;
							break;
						}
				if (!(flag1&&flag2)) // not a fake
				{
					flag = 0;
					break;
				}
			}
		if (flag)
		{
			int cnt = count(num);
			if (ret < cnt)
				ret = cnt;
		}
	}
	return ret;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int tcase = 1; tcase <= T; ++tcase)
	{
		read_data();
		printf("Case #%d: %d\n", tcase, solve());
	}

	return 0;
}

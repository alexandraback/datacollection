#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int ansmax = 1005;

int D;
int data[1005];

bool subtest(int sp, int eat)
{
	int tmp;
	int tot = 0;
	for (int i = 0; i < D; ++i)
	{
		if (data[i] > eat)
		{
			int delta = data[i] - eat;
			tmp = delta / eat;
			if (delta % eat != 0)
				++tmp;
			tot += tmp;
		}
	}
	return tot <= sp;
}

bool test(int mid)
{
	int sp;
	for (sp = 0; sp < mid; ++sp)
		if (subtest(sp, mid - sp))
			return true;
	return false;
}

int solve()
{
	cin >> D;
	for (int i = 0; i < D; ++i)
		cin >> data[i];
	int L = 0, R = ansmax;
	int mid;
	while (R - L > 1)
	{
		mid = (L + R) / 2;
		if (test(mid))
			R = mid;
		else
			L = mid;
	}
	return R;
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


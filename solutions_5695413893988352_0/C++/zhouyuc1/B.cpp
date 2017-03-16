#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool match(char s[], int num)
{
	int dn = 1;
	int ll = strlen(s);
	for (int i = ll - 1; i >= 0; --i, dn *= 10)
		if (s[i] != '?')
		{
			int digit = (num/dn)%10;
			if (digit != s[i] - '0')
				return false;
		}
	return true;
}

int absl(int a, int b)
{
	int ret = a - b;
	if (ret < 0)
		ret = -ret;
	return ret;
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int tcase = 1; tcase <= T; ++tcase)
	{
		char C[5], J[5];
		scanf("%s%s", C, J);
		int cnum, jnum;
		int cans, jans;
		int diff = 10000000;
		int ULIM = 1;
		int L = strlen(C);
		for (int i = 0; i < L; ++i)
			ULIM *= 10;
		for (cnum = 0; cnum < ULIM; ++cnum)
			for (jnum = 0; jnum < ULIM; ++jnum)
				if (match(C, cnum) && match(J, jnum))
					if (diff > absl(cnum, jnum))
					{
						diff = absl(cnum, jnum);
						cans = cnum;
						jans = jnum;
					}

		if (L == 1)
			printf("Case #%d: %d %d\n", tcase, cans, jans);
		else if (L == 2)
			printf("Case #%d: %02d %02d\n", tcase, cans, jans);
		else if (L == 3)
			printf("Case #%d: %03d %03d\n", tcase, cans, jans);
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int t;
int n, s, p;

int best_maximum(int sum, bool suprise)
{
	if (sum == 0)
		return 0;
	else if (sum == 1)
		return 1;
	else
	{
		if (!suprise)
			return sum/3 + (sum%3 > 0);
		else
			return sum/3 + 1 + (sum%3 == 2);
	}
}

int main(int argc, char *argv[])
{
	cin >> t;
	for (int index = 1; index <= t; ++index)
	{
		cin >> n >> s >> p;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			int sum;
			cin >> sum;

			if (best_maximum(sum, false) >= p)
				++count;
			else if (best_maximum(sum, true) >= p && s > 0)
			{
				++count;
				--s;
			}
		}

		printf("Case #%d: %d\n", index, count);
	}

	return 0;
}



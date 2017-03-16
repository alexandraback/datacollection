#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

const int ten[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

bool isrecycled(int m, int n)
{
	int a = m, b = n;
	while (a > 0 && b > 0)
	{
		a /= 10;
		b /= 10;
	}

	if (a + b != 0)	return false;

	for (int i = 0; m >= ten[i]; ++i)
	{
		int div = m / ten[i];
		int mod = m % ten[i];

		if (mod * ten[i] + div == n)
			return true;
	}

	return false;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int caseNum;
	scanf("%d", &caseNum);

	for (int caseId = 1; caseId <= caseNum; ++caseId)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int count = 0;
		int m = a;
		int nBit = 0;
		while (m > 0)
		{
			m /= 10;
			nBit++;
		}
		
		vector<bool> used(b + 10, false);

		for (int i = a; i <= b; ++i)
		{
			vector<int> vec;
			int m = i;
			for (int j = 0; m >= ten[j]; ++j)
			{
				int div = m / ten[j];
				int mod = m % ten[j];
				int mod2 = mod * 10 / ten[j];

				int n = mod * ten[nBit - j - 2] + div;
				if (n >= a && n <= b && m < n && mod2 != 0 && !used[n])
				{
					count++;
					vec.push_back(n);
					used[n] = true;
				}
			}

			for (int i = 0; i < vec.size(); ++i)
				used[vec[i]] = false;
		}
		printf("Case #%d: %d\n", caseId, count);
	}
	return 0;
}
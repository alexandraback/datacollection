
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;


int main()
{
	int test_cases;
	scanf("%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);

		int ans = 0;

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if ((i & j) < k)
				{
					ans++;
				}
			}
		}

		printf("Case #%d: %d\n", test_case, ans);
	}

	return 0;
}
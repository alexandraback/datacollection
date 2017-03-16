#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;


int reverseNum(int num)
{
	int res = 0;
	while (num != 0)
	{
		res *= 10;
		res += num%10;
		num /= 10;
	}
	return res;
}


int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int nTests;
	scanf("%d", &nTests);
	for (int test = 1; test <= nTests; test++)
	{
		int n;
		scanf("%d", &n);
		vector<int> maxSteps(n + 1, (int) 1e9);
		maxSteps[1] = 1;
		for (int i=0; i<n; i++)
		{
			int temp = reverseNum(i);
			if (temp > i && temp <= n)
			{
				maxSteps[temp] = min(maxSteps[temp], maxSteps[i] + 1);
			}
			maxSteps[i+1] = min(maxSteps[i+1], maxSteps[i] + 1);
		}
		printf("Case #%d: %d\n", test, maxSteps[n]);
	}

	
	return 0;
}
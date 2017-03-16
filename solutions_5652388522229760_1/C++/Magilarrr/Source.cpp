#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
set<char> digits;
int n;

void addDigits(int k)
{
	while (k != 0)
	{
		digits.insert(k % 10);
		k /= 10;
	}
}

int main()
{
	int test;
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	for (int t = 1; t <= test; t++)
	{
		scanf("%d\n", &n);
		if (n == 0)
		{
			printf("Case #%d: INSOMNIA\n", t);
			continue;
		}
		digits.clear();
		int m = 0;
		while (digits.size() != 10)
		{
			m += n;
			addDigits(m);
		}
		printf("Case #%d: %d\n", t, m);
	}
	return 0;
}
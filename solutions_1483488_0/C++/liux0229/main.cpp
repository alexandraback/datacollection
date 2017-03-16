#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A, B;

void solve(int t)
{
	printf("Case #%d: ", t + 1);

	int count = 0;

	for (int i = A; i <= B; i++)
	{
		int k = i;
		int len = 0;
		int power = 1;
		while (k > 0)
		{
			++len;
			k /= 10;
			power *= 10;
		}
		power /= 10;
		k = i;

		vector<int> upper;
		upper.reserve(len - 1);
		for (int j = 0; j < len - 1; j++)
		{
			k = (k % 10) * power + k / 10;
			if (k > i && k <= B && find(upper.begin(), upper.end(), k) == upper.end())
			{
				upper.push_back(k);
				++count;
			}
		}
	}

	printf("%d\n", count);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d %d", &A, &B);
		solve(t);
	}
}
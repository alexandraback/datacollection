#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int m[1100100];



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int A, n;
		scanf("%d%d", &A, &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m[i] );
		}
		sort(m, m + n);
		int answer = (int) 1e9, cursum = 0;
		for (int i = 0; i <= n; i++)
		{
			if (A > 1e8)
				A = 1e8;
			if (i == n)
			{
				answer = min(answer, cursum);
			}
			if (m[i] < A)
			{
				A += m[i];
				continue;
			}
			if (A == 1)
			{
				answer = n - i;
				break;
			}
			answer = min(answer, n - i + cursum);
			cursum ++;
			A += A - 1;
			i--;
		}
		printf("Case #%d: %d\n", t + 1, answer);
	}

	return 0;
}
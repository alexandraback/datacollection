#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N;
		vector<int> v;
		scanf("%d", &N);
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			int a;
			scanf("%d", &a);
			v.push_back(a);
			res = max(res, a);
		}
		for (int i = 1; i <= 1000; i++)
		{
			int s = 0;
			for (int j = 0; j < N; j++)
			{
				s += v[j] / i;
				if (v[j] % i!= 0)
					s++;
				s--;
			}
			res = min(res, s + i);
		}
		printf("Case #%d: %d\n", t+1, res);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
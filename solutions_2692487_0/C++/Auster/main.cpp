#include <stdio.h>
#include <algorithm>

using namespace std;

int T, A, N;

int motes[1 << 8];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 1; I <= T; ++I)
	{
		printf("Case #%d: ", I);
		scanf("%d", &A);
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d", &motes[i]);
		if (A == 1)
		{
			printf("%d\n", N);
			continue;
		}
		sort(motes, motes + N);
		int res = (int)1e9;
		for(int del = 0; del <= N; ++del)
		{
			int here = del;
			int cur = A;
			for(int j = 0; j < N - del; ++j)
			{
				while (cur <= motes[j])
				{
					cur += cur - 1;
					here++;
				}
				cur += motes[j];
			}
			res = min(res, here);
		}
		printf("%d\n", res);
	}
	return 0;
}
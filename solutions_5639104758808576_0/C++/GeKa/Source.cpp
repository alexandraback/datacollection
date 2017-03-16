#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N;
		char s[10000];
		scanf("%d%s", &N, s);
		int res = 0;
		int cnt = 0;
		for (int i = 0; i < N+1; i++)
		{
			if (i > cnt)
			{
				int d = i - cnt;
				res += d;
				cnt+=d;
			}
			cnt += s[i] - '0';
		}
		printf("Case #%d: %d\n", t+1, res);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
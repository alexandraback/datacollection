#include <iostream>
using namespace std;

int T, N, S, P;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		int ans = 0, s = 0;
		scanf("%d%d%d", &N, &S, &P);
		for(int i = 0; i < N; ++i)
		{
			int n, a1, a2, a3;
			scanf("%d", &n);
			if(n % 3 == 0)
				a1 = a2 = a3 = n / 3;
			else if(n % 3 == 1)
				a1 = a2 = (n - 1) / 3, a3 = (n - 1) / 3 + 1;
			else
				a1 = (n - 2) / 3, a2 = a3 = (n - 2) / 3 + 1;

			if(a3 >= P)
				++ans;
			else
			{
				if(n % 3 == 0)
					a1 = n / 3 - 1, a2 = n / 3, a3 = n / 3 + 1;
				else if(n % 3 == 1)
					a1 = (n - 1) / 3 - 1, a2 = a3 = (n - 1) / 3 + 1;
				else
					a1 = a2 = (n - 2) / 3, a3 = (n - 2) / 3 + 2;
				if(a1 >= 0 && a2 >= 0 && a3 >= 0 && a1 <= 10 && a2 <= 10 && a3 <= 10 && s < S && a3 >= P)
					++s, ++ans;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
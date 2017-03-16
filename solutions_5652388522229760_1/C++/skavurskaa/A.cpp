#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		long long N; cin >> N;
		if (!N) printf("Case #%d: INSOMNIA\n", t);
		else
		{
			set<int> used;
			long long X = 0;
			do
			{
				X += N;
				long long x = X;
				while (x)
				{
					used.insert(x%10);
					x /= 10;
				}
			} while (used.size() != 10);
			printf("Case #%d: %lld\n", t, X);
		}
	}
}

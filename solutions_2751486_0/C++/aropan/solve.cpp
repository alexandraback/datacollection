#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXL = 1000007;

char s[MAXL];

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		int m;
		scanf("%s %d", s, &m);
		int n = strlen(s);
		long long ans = 0;
		int l = -1;
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'i' && s[i] != 'u')
				k += 1;
			else
				k = 0;
			if (k >= m)
			{
				ans += (n - i) * (long long)(i - m - l + 1);
				l = i - m + 1;
			}
		}
		cout << ans;
		printf("\n");
	}
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}

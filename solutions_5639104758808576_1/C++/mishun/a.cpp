#include <cstdio>
#include <algorithm>


int main()
{
	freopen("input.txt", "r", stdin);

	int t;
	scanf("%i\n", &t);
	for(int tn = 1; tn <= t; tn++)
	{
		int n;
		char s[2048];
		scanf("%i %s\n", &n, s);

		int r = 0, left = 0;
		for(int i = 0; i <= n; i++)
		{
			int cur = (int)(s[i] - '0');
			if(cur > 0 && i > left)
				r = std::max(r, i - left);
			left += cur;
		}

		printf("Case #%i: %i\n", tn, r);
	}

	return 0;
}


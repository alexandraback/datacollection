#include <bits/stdc++.h>
using namespace std;

char S[111];

int main()
{
	int T, ans, l, v;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%s", S);
		ans = 0;
		l = strlen(S);
		for (int i = l - 1; i >= 0; i--)
		{
			v = (S[i] == '+') ? 0 : 1;
			if ((v + ans) & 1)
				ans++;
		}
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
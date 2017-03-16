#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, t, R, C, W, ans, p2, top;
	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		ans = 0;
		scanf("%d%d%d", &R, &C, &W);
		ans = (C / W) * R;
		
		if (C % W == 0)
			ans += (W - 1);
		else
			ans += W;

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
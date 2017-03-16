#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, r, c, w;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cin >> r >> c >> w;
		int res = r * c;
		if (w != 1) {
			res = r * (c/w) + w - 1;
			if (c % w != 0)
				res++;
		}
		printf("Case #%d: %d\n", tt, res);
	}

	return 0;
}
#include <iostream>

using namespace std;

int solve(int R, int C, int W)
{
	if (C == W)
	{
		return R - 1 + W;
	}

	if (W == 1)
	{
		return R * C;
	}

	int ans = 0;
	ans += (R - 1) * (C / W);

	while (C > 2 * W)
	{
		ans++;
		C -= W;
	}

	ans += (W + 1);

	return ans;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int R, C, W;
		cin >> R >> C >> W;

		cout << "Case #" << i << ": " << solve(R, C, W) << endl;
	}

	return 0;
}
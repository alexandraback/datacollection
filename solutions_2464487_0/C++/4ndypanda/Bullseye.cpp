#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int n = 1; n <= T; n++)
	{
		long long r, t;
		cin >> r >> t;
		int cnt = 0, paint = 0, x = 1;
		while (1)
		{
			int need = 2 * r + 2 * x - 1;
			if (paint + need > t)
				break;
			cnt++;
			paint += need;
			x += 2;
		}
		printf("Case #%d: %lld\n", n, cnt);
	}
	return 0;
}
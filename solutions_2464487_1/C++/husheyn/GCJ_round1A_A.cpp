#include <iostream>
#include <string.h>

using namespace std;

typedef long long LL;

int T;
LL r, t;

int main()
{
	freopen("A-large (1).in", "r", stdin);
	freopen("A-large (1).out", "w", stdout);
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cin >> r >> t;
		LL L = 0, R = t / r;
		while (L < R)
		{
			LL mid = (L + R) / 2;
			if (2 * mid * mid + (2 * r - 1) * mid <= t)
				L = mid + 1;
			else
				R = mid;
		}
		cout << "Case #" << i << ": " << L - 1 << endl;
	}
	return 0;
}

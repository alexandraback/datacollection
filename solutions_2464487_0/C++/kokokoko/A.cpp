#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char * argv[])
{
	freopen(argv[1], "r", stdin);
	freopen(argv[2], "w", stdout);

	int T;
	cin >> T;
	for (int t=0; t<T; t++)
	{
		long double rr, tt;
		cin >> rr >> tt;
		long double ans = (1 - 2*rr + sqrt((2*rr-1)*(2*rr-1) + 8 * tt)) * 0.25;
		long long ans1 = (long long)ans;

		while (ans1 > 0 && 2 * ans1 * ans1 + (2 * rr - 1) * ans1 > tt)
			ans1 --;

		cout << "Case #" << t+1 << ": " << ans1 << endl;
	}

	return 0;
}


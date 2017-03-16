#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;


bool Check(long long k, long long r, long long t)
{
	return 2 * r + 2 * k - 1 <= t / k;
}

long long Work()
{
	long long r, t;
	cin >> r >> t;
	long long ll = 1, rr = t, mid;
	while (ll < rr)
	{
		mid = (ll + rr + 1) >> 1;
		if (Check(mid, r, t)) ll = mid;
		else rr = mid - 1;
	}
	return ll;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-out.txt", "w", stdout);

	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt ++)
		cout << "Case #" << tt << ": " << Work() << endl;

	return 0;
}
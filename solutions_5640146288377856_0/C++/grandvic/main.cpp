#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iterator>

using namespace std;

void solve()
{
	int Y, X, w; cin >> Y >> X >> w;
	int prem1 = X / w;
	int p2 = X - (prem1 - 1) * w;
	int result = prem1 * Y - 1;
	if (p2 == w)
		result += w;
	else
		result += w + 1;

	cout << result << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("d:/input.txt", "rt", stdin);
	int T; std::cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}
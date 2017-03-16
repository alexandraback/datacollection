#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void solve()
{
	int r, c, w;
	cin >> r >> c >> w;
	int spr = c / w;
	int fht = r * spr;
	int num = fht + w - 1;
	if (c % w != 0) num += 1;
	cout << num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
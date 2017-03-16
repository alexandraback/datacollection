#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

#define pie pair <int, int>
#define ff first
#define ss second

const int maxN = 1000 + 10;

int n, a[maxN], b[maxN];
int flag[maxN];

void solve () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	int star = 0, res = 0;
	memset (flag, 0, sizeof flag);
	for (; star < 2 * n; ) {
		int fnd = 0;
		for (int i = 0; i < n; i++)
			if (b[i] <= star && flag[i] < 2) {
				star += 2 - flag[i];
				flag[i] = 2;
				fnd = 1;
				res++;
				break;
			}
		if (fnd) continue;
		int best = -1;
		for (int i = 0; i < n; i++)
			if (a[i] <= star && flag[i] < 1) {
				if (best == -1 || b[best] < b[i])
					best = i;
			}
		if (best != -1) {
			star += 1 - flag[best];
			flag[best] = 1;
			fnd = 1;
			res++;
		}
		if (!fnd) {
			cout << "Too Bad" << endl;
			return;
		}
	}

	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int i = 1; i <= tests; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}

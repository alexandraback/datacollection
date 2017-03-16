#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void solve()
{
	int c, d, v;
	cin >> c >> d >> v;
	int value[d];
	for (int i=0; i<d; i++) cin >> value[i];
	
	bool p[v+1];
	fill_n(p, v+1, false);
	for (int i=0; i<(1<<d); i++) {
		int sum = 0;
		for (int j=0; j<d; j++) {
			if (i & (1 << j)) sum += value[j];
		}
		if (sum <= v) p[sum] = true;
	}
	
	int newCoins = 0;
	for (int i=0; i<=v; i++) {
		if (!p[i]) {
			//cout << "Coin " << i << " is missing!" << endl;
			newCoins++;
			for (int j=v-i; j>=0; j--) {
				if (p[j]) p[j+i] = true;
			}
		}
	}
	
	cout << newCoins;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": " << flush;
		solve();
		cout << endl;
	}
	return 0;
}
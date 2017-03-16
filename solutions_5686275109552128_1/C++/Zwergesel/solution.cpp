#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void solve()
{
	int D;
	cin >> D;
	vector<size_t> p(1001, 0);
	int pmax = 0;
	for (int i=0; i<D; i++) {
		int pi;
		cin >> pi;
		p[pi]++;
		pmax = max(pmax, pi);
	}
	
	int best = pmax;
	for (int E=1; E<pmax; E++) {
		int steps = E;
		for (int i=1; i<=pmax; i++) {
			steps += p[i] * ((i - 1) / E);
		}
		best = min(best, steps);
	}
	
	cout << best;
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
		cout << endl;
	}
	return 0;
}
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int srec(vector<size_t>::iterator p, int steps, int m)
{
	while (m > 0 && p[m] == 0) --m;
	if (m == 0) return steps;
	if (m == 1) return steps + 1;
	// Split stack
	int best = 10000;
	for (int i=1; i<=m/2; i++) {
		p[i] += p[m];
		p[m-i] += p[m];
		best = min(best, srec(p, steps+p[m], m-1));
		p[i] -= p[m];
		p[m-i] -= p[m];
	}
	// Wait and let them eat
	best = min(best, srec(p+1, steps+1, m-1));
	return best;
}

void solve()
{
	int D;
	cin >> D;
	vector<size_t> p(1001, 0);
	for (int i=0; i<D; i++) {
		int pi;
		cin >> pi;
		p[pi]++;
	}
	
	cout << srec(p.begin(), 0, 1000);
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
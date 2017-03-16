#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void solve()
{
	int n;
	string shy;
	cin >> n >> shy;
	int clap(0), invite(0);
	for (int i=0; i<=n; i++) {
		if (clap < i) {
			invite += i - clap;
			clap = i;
		}
		clap += shy[i] - '0';
	}
	cout << invite;
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

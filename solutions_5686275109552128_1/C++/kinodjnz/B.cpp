#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int solve(const vector<int> &P)
{
	int ans = (1<<29);
	for (int i = 1; i <= 1000; i++) {
		int r = i;
		for (auto j = P.begin(); j != P.end(); ++j) {
			if (*j > i) {
				r += (*j - 1) / i;
			}
		}
		ans = min(ans, r);
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int D;
		vector<int> P;
		cin >> D;
		for (int i = 0; i < D; i++) {
			int p;
			cin >> p;
			P.push_back(p);
		}
		int ans = solve(P);
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
}

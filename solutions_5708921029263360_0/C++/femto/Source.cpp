#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int K;
struct Set {
	int j, p, s;
};

vector<Set> b;
vector<Set> v;
vector<Set> ans;

int pa[1000] = { 0 };

void dfs(int n) {
	if(b.size() == n) {
		if(ans.size() < v.size()) {
			ans = v;
		}
		return;
	}

	dfs(n + 1);

	int c = b[n].j * 100 + b[n].p * 10 + b[n].s;
	int p1 = c - 100 * b[n].j, p2 = c - 10 * b[n].p, p3 = c - b[n].s;
	if(pa[p1] < K && pa[p2] < K && pa[p3] < K) {
		pa[p1]++, pa[p2]++, pa[p3]++;
		v.push_back(b[n]);

		dfs(n + 1);
		pa[p1]--, pa[p2]--, pa[p3]--;
		v.pop_back();
	}

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int loop = 1; loop <= T; loop++) {
		int J, P, S;
		cin >> J >> P >> S >> K;

		ans.clear();
		b.clear();
		v.clear();
		for(int j = J; j >= 1; j--) {
			for(int p = P; p >= 1; p--) {
				for(int s = S; s >= 1; s--) {
					b.push_back(Set{ j, p, s });
				}
			}
		}
		dfs(0);

		cout << "Case #" << loop << ": " << ans.size() << endl;
		for(Set a : ans) {
			cout << a.j << " " << a.p << " " << a.s << endl;
		}
	}
}
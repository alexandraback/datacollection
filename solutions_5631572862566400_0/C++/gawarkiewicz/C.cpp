#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;

bool check(vector<vector<int>>& F, vector<int>& circle, int v=0) {
	for (int i = 0+v; i < circle.size()-v; ++i) {
		if (F[circle[i]][0] != circle[(i + 1) % circle.size()] && F[circle[i]][0] != circle[(i - 1 + (int)circle.size()) % circle.size()]) {
			return false;
		}
		assert(F[circle[i]][0] == circle[(i + 1) % circle.size()] || F[circle[(i + 1) % circle.size()]][0] == circle[i]);
	}
	return true;
}

void solve(vector<vector<int>>& F, vector<bool>& used, int cur, vector<int>& circle, int& ret) {
	if (ret < circle.size() && check(F, circle)) {
		ret = circle.size();
		assert(ret > 1 && ret < F.size());
	}
	if (circle.size() > 0 && !check(F, circle, 1)) return;
	if (used[cur]) {
		return;
	}
	used[cur] = true;
	circle.push_back(cur);
	for (int i = 0; i < F.size()/*F[cur].size()*/; ++i) {
		solve(F, used, i/*F[cur][i]*/, circle, ret);
	}
	used[cur] = false;
	circle.pop_back();
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cerr << t << endl;
		int N;
		cin >> N;
		vector<vector<int>> F(N);
		for (int i = 0; i < N; ++i) {
			int c;
			cin >> c;
			--c;
			F[i].push_back(c);
		}
		for (int i = 0; i < N; ++i) {
			F[F[i][0]].push_back(i);
		}
		vector<bool> used(N, false);
		vector<int> circle;
		int ret = 0;
		for (int i = 0; i < N; ++i) {
			solve(F, used, i, circle, ret);
		}

		cout << "Case #" << t << ": " << ret << endl;
	}
	return 0;
}
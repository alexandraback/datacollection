#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;

bool check(vector<vector<int>>& F, vector<int>& circle, int v=0) {
	if (v) {
		if (circle.size() >= 3) {
			int i = circle.size() - v - 1;
			if (F[circle[i]][0] != circle[(i + 1) % circle.size()] && F[circle[i]][0] != circle[(i - 1 + (int)circle.size()) % circle.size()]) {
				return false;
			}
		}
	}
	else {
		for (int i = 0 + v; i < circle.size() - v; ++i) {
			if (i > 0 && circle.size() > 1) i = circle.size() - 1;
			if (F[circle[i]][0] != circle[(i + 1) % circle.size()] && F[circle[i]][0] != circle[(i - 1 + (int)circle.size()) % circle.size()]) {
				return false;
			}
			//assert(F[circle[i]][0] == circle[(i + 1) % circle.size()] || F[circle[(i + 1) % circle.size()]][0] == circle[i]);
		}
	}
	return true;
}

void solve(vector<vector<int>>& F, vector<bool>& used, int cur, vector<int>& circle, int& ret) {
	if (used[cur]) {
		return;
	}
	used[cur] = true;
	circle.push_back(cur);
	//if (circle.size() < 7) cerr << "\t\t" << circle.size() << endl;
	if (check(F, circle, 1)) {
		//if (ret < circle.size()) cerr << "checking" << endl;
		if (ret < circle.size() && check(F, circle)) {
			ret = circle.size();
			cerr << "\t" << ret << endl;
			assert(ret > 1 && ret < F.size());
		}
		if (circle.size() >= 2 && F[circle[circle.size() - 1]][0] != circle[circle.size() - 2]) {
			solve(F, used, F[circle[circle.size() - 1]][0], circle, ret);
		}
		else
			for (int i = 0; i < F[cur].size(); ++i) {
			if (!used[i])
			solve(F, used, i/*F[cur][i]*/, circle, ret);
		}
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
/*for (int i = 0; i < 990; ++i) {
	F.resize(F.size()+1); F[i + N].push_back(rand() % 990);
}N = F.size();*/
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
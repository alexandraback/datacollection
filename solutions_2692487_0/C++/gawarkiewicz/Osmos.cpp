#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<map<int, int>>> buf;

int solve(vector<int>& we, int from, int to, int A) {
/*	auto& m = buf[from][to];
	auto it = m.find(A);
	if (it != m.end())
		return it->second;
	int& ret = m[A];*/
	if (from == to) return 0;
	if (A > we[from]) {
		return /*ret = */solve(we, from+1, to, A+we[from]);
	}
	if (A == 1) return we.size();
	if (to-from == 1) return 1;
	int ret1 = 1+solve(we, from, to-1, A);
	int ret2 = 1+solve(we, from, to, A+A-1);
	return /*ret =*/ min(ret1, ret2);
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		int A, N;
		cin >> A >> N;
		buf.clear();
		buf.resize(N+1);
		for (int i=0; i<=N; ++i) {
			buf[i].resize(N+1);
		}
		vector<int> we(N);
		for (int i=0; i<N; ++i) {
			cin >> we[i];
		}
		sort(we.begin(), we.end());

		int ret = 0;
		cout << "Case #" << t << ": " << solve(we, 0, N, A) << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

long long target = 0;
string ans;

void visit(const vector<string>& zip, map<int, set<int>>& out, map<int, set<int>>& ret, string s, int cur, long long visited)
{
	if ((visited & (1LL << cur)) == 0){
		visited += (1LL << cur);
		s += zip[cur];
	}
	if (visited == target) {
		if (ans.empty() || s.size() < ans.size() || s < ans) {
			ans = s;
		}
		return;
	}

	if (!ans.empty() && s.size() > ans.size()) {
		return;
	}

	auto next = out[cur];
	for (auto n : next) {
		if (visited & (1LL << n)) continue;
		out[cur].erase(n);
		out[n].erase(cur);
		ret[n].insert(cur);
		visit(zip, out, ret, s, n, visited);
		ret[n].erase(cur);
		out[n].insert(cur);
		out[cur].insert(n);
	}

	next = ret[cur];
	for (auto n : next) {
		ret[cur].erase(n);
		visit(zip, out, ret, s, n, visited);
		ret[cur].insert(n);
	}
}

int main()
{
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cerr << t << endl;
		int N, M;
		cin >> N >> M;
		vector<string> zip(N);
		map<int, set<int>> chckets, ret;
		for (int i = 0; i < N; i++ ) {
			cin >> zip[i];
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			chckets[a-1].insert(b-1);
			chckets[b-1].insert(a-1);
		}
		target = (1LL << N) - 1;
		ans = "";
		for (int i = 0; i < N; i++) {
			visit(zip, chckets, ret, "", i, 0);
		}
		printf("Case #%d: %s\n", t, ans.c_str());
	}

	return 0;
}

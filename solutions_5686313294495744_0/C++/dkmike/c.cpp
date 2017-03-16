#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<string, string> pss;

int check(const vector<int>& p, const int N, const vector <pss>& topics) {
	int ans = 0;
	for (int i = 2; i < N; ++i) {
		bool f1 = false;
		bool f2 = false;
		for (int j = 0; j < i; ++j) {
			if (f1 && f2) {break;}
			int ii = p[i];
			int jj = p[j];

			f1 = f1 || (topics[ii].first == topics[jj].first);
			f2 = f2 || (topics[ii].second == topics[jj].second);
		}

		if (f1 && f2) {
			++ans;
		}
	}

	return ans;
}

void solve1(int t, const int N, const vector <pss>& topics) {
	vector<int> p(N);
	for (int i = 0; i < N; ++i) {
		p[i] = i;
	}

	int best = 0;
	do {
		const int fakes = check(p, N, topics);
		best = max(best, fakes);
	} while (next_permutation(p.begin(), p.end()));

	cout << "Case #" << t << ": " << best << endl;
}

void solve(const int t) {
	int N = 0;
	cin >> N;

	vector <pss> topics;
	for (int i = 0; i < N; ++i) {
		string a, b;
		cin >> a >> b;
		topics.emplace_back(a, b);
	}

	if (N < 10) { solve1(t, N, topics); return; }

	vector <int> fake(N);
	vector <pss> fakeT;
	for (int i = 0; i < N; ++i) {
		bool f1 = false;
		bool f2 = false;

		for (int j = 0; j < N; ++j) {
			if (f1 && f2) {
				break;
			}
			if (i == j) {
				continue;
			}

			f1 = f1 || (topics[i].first == topics[j].first);
			f2 = f2 || (topics[i].second == topics[j].second);
		}

		fake[i] = f1 && f2;
		if (fake[i]) {
			fakeT.emplace_back(topics[i]);
		}
	}

	int ans = 0;
	const int FN = (int)fakeT.size();
	for (int i = 0; i < FN; ++i) {
		bool f1 = false;
		bool f2 = false;
		for (int j = 0; j < N; ++j) {
			if (f1 && f2) {	break; }
			if (fake[j]) { continue; }

			f1 = f1 || (fakeT[i].first == topics[j].first);
			f2 = f2 || (fakeT[i].second == topics[j].second);
		}

		if (f1 && f2) {
			++ans;
		}
	}

	const int pureFake = FN - ans;
	const int k = (int)(ceil(sqrt(1.0 * pureFake)) + 0.5);

	ans += pureFake - k;

	cout << "Case #" << t << ": " << ans << endl;
}

int main() {
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}

	return 0;
}

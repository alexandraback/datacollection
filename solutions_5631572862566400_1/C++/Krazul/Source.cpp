#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int bff[2000];
vector<vector<int> > rev;

int largest_cycle() {
	int best = 0;
	bool seen[2000];
	for (int i = 0; i < n; ++i) seen[i] = false;
	for (int i = 0; i < n; ++i) {
		if (seen[i]) continue;
		stack<int> s;
		int curr = i;
		while (!seen[curr]) {
			seen[curr] = true;
			s.push(curr);
			curr = bff[curr];
		}
		int size = 1; bool failure = false;
		while (s.top() != curr) {
			size++;
			s.pop();
			if (s.empty()) {
				failure = true;
				break;
			}
		}
		if (!failure) best = max(best, size);
	}
	return best;
}

bool in_two_cycle(int v) {
	return (bff[bff[v]] == v);
}

void recompute_rev() {
	rev.clear();
	rev.resize(n);
	for (int i = 0; i < n; ++i) {
		if (!in_two_cycle(i)) rev[bff[i]].push_back(i);
	}
}

int longest_chain_ending_in(int v) {
	int ans = 1;
	for (int i = 0; i < rev[v].size(); ++i) {
		ans = max(ans, longest_chain_ending_in(rev[v][i]) + 1);
	}
	return ans;
}

int main() {
	int t; cin >> t;
	for (int test = 1; test <= t; ++test) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> bff[i]; bff[i]--;
		}
		// Possibility 1: (---> TWO CYCLE <---)
		recompute_rev();
		int answer = 0;
		for (int i = 0; i < n; ++i) {
			if (in_two_cycle(i)) {
				answer += longest_chain_ending_in(i);
			}
		}
		//cout << "Two Cycles+ Length: " << answer << endl;
		// Possibility 2: LARGE CYCLE
		answer = max(answer, largest_cycle());
		//cout << "Largest Cycle: " << largest_cycle() << endl;
		cout << "Case #" << test << ": " << answer << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
	int diners_count;
	cin >> diners_count;
	vector<int> diners_pancakes(diners_count);
	for (int i = 0; i < diners_count; ++i)
		cin >> diners_pancakes[i];
	int max_pancakes = *max_element(diners_pancakes.begin(), diners_pancakes.end());
	int answer = numeric_limits<int>::max();
	for (int i = 1; i <= max_pancakes; ++i) {
		int cur_answer = i;
		for (int j = 0; j < diners_count; ++j)
			cur_answer += (diners_pancakes[j] + i - 1) / i - 1;
		answer = min(answer, cur_answer);
	}
	return answer;
}

int main() {
	FILE *f;
	freopen_s(&f, "in.txt", "rt", stdin);
	freopen_s(&f, "out.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int test_num = 1; test_num <= t; ++test_num) {
		int ans = solve();
		cout << "Case #" << test_num << ": " << ans << endl;
	}
}
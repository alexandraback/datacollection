#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <tuple>
#include <queue>
#include <utility>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <limits>
#include <new>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		priority_queue<pair<int, int>> pq;
		for (int p = 0; p < P; p++) {
			for (int s = 0; s < S; s++) {
				pq.push(make_pair(K, p * 100 + s));
			}
		}
		string output = "";
		int count = 0;
		for (int j = 0; j < J; j++) {
			vector<pair<int, int>> cp;
			while (!pq.empty()) {
				cp.push_back(pq.top());
				pq.pop();
			}
			vector<int> countp(P, 0);
			vector<int> counts(S, 0);
			for (auto& x : cp) {
				if (countp[x.second / 100] < K && counts[x.second % 100] < K) {
					countp[x.second / 100]++;
					counts[x.second % 100]++;
					x.first--;
					output += to_string(j + 1);
					output += ' ';
					output += to_string(x.second / 100 + 1);
					output += ' ';
					output += to_string(x.second % 100 + 1);
					output += '\n';
					count++;
				}
				if (x.first > 0) pq.push(x);
			}
		}
		cout << "Case #" << tt << ": " << count << "\n" << output;
	}

	return 0;
}
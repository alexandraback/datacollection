#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <utility>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		vector<tuple<int, int, int>> outfits;
		map<pair<int, int>, int> jp, js, ps;
		for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int s = 1; s <= S; ++s) {
					if (jp[{j, p}] < K && js[{j, s}] < K && ps[{p, s}] < K) {
						++jp[{j, p}];
						++js[{j, s}];
						++ps[{p, s}];
						outfits.push_back(tuple<int, int, int>(j, p, s));
					}
				}
			}
		}
		cout << "Case #" << t << ": " << outfits.size() << endl;
		for (auto el : outfits)
			cout << get<0>(el) << " " << get<1>(el) << " " << get<2>(el) << endl;
	}
}
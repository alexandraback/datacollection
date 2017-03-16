#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

/*pair<int, int> make_pair(int a, int b) {
	pair<int, int> ret;
	ret.first = min(a, b);
	ret.first = max(a, b);
	return ret;
}*/

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		vector<vector<int>> out, out2;
		vector<vector<int>> all;
		{
			map<pair<int, int>, int> p12, p13, p23;
			for (int j = 1; j <= J; ++j) {
				bool p2 = j % 2;
				for (int p = (p2 ? 1 : P); (p2 ? p <= P : p >= 1); (p2 ? ++p : --p)) {
					bool s2 = p % 2;
					if (!p2) s2 = !s2;
					for (int s = (s2 ? 1 : S); (s2 ? s <= S : s >= 1); (s2 ? ++s : --s)) {
						if (p12[make_pair(j, p)] < K && p13[make_pair(j, s)] < K && p23[make_pair(p, s)] < K) {
							out2.push_back({ j, p, s });
							++p12[make_pair(j, p)];
							++p13[make_pair(j, s)];
							++p23[make_pair(p, s)];
						}
					}
				}
			}
		}
		/*for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int s = 1; s <= S; ++s) {
					all.push_back({ j, p, s });
				}
			}
		}
		sort(all.begin(), all.end(), [](vector<int>& a, vector<int>& b) {
			return set<int>(a.begin(), a.end()).size() > set<int>(b.begin(), b.end()).size();

		});
		{
			map<pair<int, int>, int> p12, p13, p23;
			for (auto& a : all) {
				int j = a[0], p = a[1], s = a[2];
				if (p12[make_pair(j, p)] < K && p13[make_pair(j, s)] < K && p23[make_pair(p, s)] < K) {
					out.push_back({ j, p, s });
					++p12[make_pair(j, p)];
					++p13[make_pair(j, s)];
					++p23[make_pair(p, s)];
				}
			}
		}*/
		if (out2.size() > out.size()) out = out2;
		cout << "Case #" << q << ": " << out.size() << endl;
		for (auto& o : out) {
			cout << o[0] << " " << o[1] << " " << o[2] << endl;
		}
	}
	return 0;
}
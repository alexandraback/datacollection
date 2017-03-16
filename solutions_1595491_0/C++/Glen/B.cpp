//2012-04-14T09:01:29

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mygreater(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main(int argc, char const* argv[])
{
	int T;
	cin >> T;
	for (int ii = 0; ii < T; ii++) {
		vector< pair<int, int> > scores; // pair: flat score, mod

		int N, S, P;
		cin >> N >> S >> P;
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			scores.push_back(pair<int, int>(t / 3, t % 3));
		}
		sort(scores.begin(), scores.end(), mygreater);

		int ans = 0;
		int surprisings = 0;
		for (int i = 0; i < scores.size(); i++) {
			pair<int, int> score = scores.at(i);
			//cout << "Total: " << score.first * 3 + score.second << ", Flat: " << score.first << ", Mod: " << score.second << endl;
			if (score.second == 1) {
				if (score.first + 1 >= P) {
					++ans;
				}
			} else if (score.second == 0) {
				if (score.first >= P) {
					++ans;
				} else if (surprisings < S && score.first + 1 >= P && score.first * 3 + score.second != 0) {
					++surprisings;
					++ans;
				}
			} else { // mod == 2
				if (score.first + 1 >= P) {
					++ans;
				} else if (surprisings < S && score.first + 2 >= P) {
					++surprisings;
					++ans;
				}
			}
			//cout << "\tsurprisings: " << surprisings << endl;
		}

		cout << "Case #" << ii + 1 << ": " << ans << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<double, int> di;
typedef vector<double> vd;
typedef vector<di> vdi;
typedef multiset<double> sd;

bool is_good(const sd& other, double th, double total)
{
	for (sd::iterator it = other.begin(); it != other.end(); ++it) {
		if (*it < th) {
			total -= (th - *it);
		}
	}
	return (total < 0);
}


int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		vi scores(N, 0);
		double X = 0;
		for (int i = 0; i < N; ++i) {
			cin >> scores[i];
			X += scores[i];
		}
		vd scores1(N, 0);
		for (int i = 0; i < N; ++i) {
			scores1[i] = scores[i] / X;
		}
		cout << "Case #" << t+1 << ':';
		cout.precision(8);
		for (int i = 0; i < N; ++i) {
			// contentant i
			// put all _other_ scores in a set
			sd other;
			for (int j = 0; j < N; ++j) {
				if (j == i) continue;
				other.insert(scores1[j]);
			}
			// do a binary search on the right value
			double low = 0, high = 1;
			while (high - low > 1e-8) {
				double mid = (low + high) / 2;
				if (is_good(other, scores1[i]+mid, 1-mid)) {
					high = mid;
				} else {
					low = mid;
				}
			}
			cout << ' ' << low*100;
		}
		cout << endl;
	}
	return 0;
}

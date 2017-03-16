#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		vector<int> data;
		int totalScore = 0;
		for (int i = 0; i < N; i++) {
			int val; cin >> val; data.push_back(val);
			totalScore += val;
		}
		double lo = 0;
		double hi = 11000;
		int iter = 0;
		while (lo <= hi && iter++ < 150) {
			double mid = (lo + hi) / 2;
			// possible?
			double portion = 0.0;
			for (int i = 0; i < data.size(); i++) {
				if (data[i] > mid) continue;	// don't need
				double needMore = mid-data[i];
				portion += (needMore / totalScore);
			}
			bool poss = true;
			if (portion > 1.0) {
				poss = false;
			}
			if (poss) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << "Case #" << (t+1) << ": ";
		for (int i = 0; i < data.size(); i++) {
			if (i != 0) printf(" ");
			if (data[i] > lo) printf("%.6f",0.0f);
			else printf("%.6f",(lo-data[i])/totalScore*100.0);
		}
		cout << "\n";
	}
	return 0;
}
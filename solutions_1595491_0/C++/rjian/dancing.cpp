#include <iostream>
#include <vector>
using namespace std;

int T;
int main() {
	cin >> T;
	for(int t = 0; t < T; ++t) {	
		int n, s, p, ans = 0;
		vector<int> scores;
		cin >> n >> s >> p;
		for(int i = 0; i < n; ++i) {
			int temp;
			cin >> temp;
			scores.push_back(temp);
		}
		for(int i = 0; i < scores.size(); ++i) {
			int best = 0;
			for(int j = 0; j <= 10; ++j) {
				for(int k = 0; k <= 1; ++k) {
					for(int l = 0; l <= 1; ++l) {
						if(j + l > 10 || k + k > 10) {
							continue;
						}
						if(j + (j + k) + (j + l) == scores[i]) {
							best = max(best, max(j, max(j+k, j + l)));
						}
					}
				}
			}
			if(best >= p) { ans++; }
			else if(s > 0) {
				int best = 0;
				for(int j = 0; j <= 10; ++j) {
					for(int k = 0; k <= 2; ++k) {
						for(int l = 0; l <= 2; ++l) {
							if(j + l > 10 || k + k > 10) {
								continue;
							}
							if(j + (j + k) + (j + l) == scores[i]) {
								best = max(best, max(j, max(j+k, j + l)));
							}
						}
					}
				}
				if(best >= p) { ans++; s--; }
			}
		}	
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}

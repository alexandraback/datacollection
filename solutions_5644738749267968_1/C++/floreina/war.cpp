#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long double ld;

int solve_low(vector <ld> naomi, vector <ld> ken) {
	int score = 0;
	for(int i = naomi.size() - 1; i >= 0; --i) {
		int j;
		for(j = 0; j < ken.size() && ken[j] < naomi[i]; ++j);
		if(j == ken.size()) {
			++score;
			ken.erase(ken.begin());
		} else {
			ken.erase(ken.begin() + j);
		}
	}
	return score;
}
int solve_high(vector <ld> naomi, vector <ld> ken) {
	int score = 0;
	while(naomi.size() > 0) {
		if(*naomi.begin() > *ken.begin()) {
			++score;
			ken.erase(ken.begin());
		} else {
			ken.pop_back();
		}
		naomi.erase(naomi.begin());
	}
	return score;
}

int main() {
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		auto process_input = [n](vector <ld> &v) {
			v.clear();
			for(int i = 0; i < n; ++i) {
				ld w; cin >> w; v.push_back(w);
			}
			sort(v.begin(), v.end());
		};
		vector <ld> naomi, ken;
		process_input(naomi); process_input(ken);
		cout << "Case #" << t + 1 << ": " << solve_high(naomi, ken) << ' ' << solve_low(naomi, ken) << endl;
	}
}
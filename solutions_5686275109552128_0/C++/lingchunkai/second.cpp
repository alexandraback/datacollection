#include <iostream>
#include <vector>
using namespace std;


int cutty(int n, int cuts) {
	if (cuts == 0) return n;
	if (n % (cuts+1) > 0) return n/(cuts+1) + 1;
	else return n/(cuts+1);
}

int solve(vector<int>& score_buggers) {
	int table[1001] = {0};

	// Dee Pee
	for (int x = 0; x < score_buggers.size(); x++){

		int temptable[1001];
		for (int k = 0; k < 1001; k++) temptable[k] = 99999;
		for (int j = 0; j < 1001; j++) {
			for (int y = 0; y < 40; y++) {
				if (j+y>1000) continue;
				temptable[j+y] = min(temptable[j+y], max(table[j], cutty(score_buggers[x], y)));
				//cout << temptable[j+y] << endl;
			}
		}
		for (int k = 0; k < 1001; k++) table[k] = temptable[k];
	}

	int m = 1000000;
	int ww = -1;
	for (int k = 0; k < 1001; k++) {
		if (table[k]+k < m) ww = k;
		m = min(m, table[k] + k);
		// cout << k << endl;
	}
	// cout << ww << endl;;
	return m;
}

int main() {

	int T;
	cin >> T;


	for (int t = 0; t < T; t++) {

		int num_buggers;
		cin >> num_buggers;
		vector<int> score_buggers;

		for (int x = 0; x < num_buggers; x++) {
			int pewpewpew;
			cin >> pewpewpew;
			score_buggers.push_back(pewpewpew);
		}

		cout << "Case #" << t+1 << ": " << solve(score_buggers) << endl;;



	}

	return 0;
}
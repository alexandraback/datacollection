#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++) {
		cout << "Case #" << kase << ": ";
		int n;
		cin >> n;
		vector<string> ss;
		vector<int> is(n, 0);
		int ml = 0;
		for (int i  = 0; i < n; i++) {
			string s;
			cin >> s;
			ss.push_back(s);
			ml = max(ml, (int)s.length());
		}

		bool broken = false;
		int cost = 0;
		//for each letter
		while (!broken) {
			if (is[0] == ss[0].size()) { //done
				for (int i = 1; i < ss.size(); i++) {
					if (is[i] != ss[i].length()) {
						broken = true;
						//cerr << "1st string ended, others didn't" << endl;
					} 
				}
				break;
			} else { // calc lens of runs of char in each string
				char l = ss[0][is[0]];
				//cerr << l << endl;
				vector<int> lens;
				for (int i = 0; i < ss.size(); i++) {
					if (is[i] == ss[i].length() || ss[i][is[i]] != l) {
						broken = true;
						break;
					} else {
						int len = 0;
						while (ss[i][is[i]] == l && is[i] < ss[i].length()) {
							len++;
							is[i]++;
						}
						lens.push_back(len);
					}
				}
				//calc diffs from lens
				sort(lens.begin(), lens.end());
				for (int i = 0; i < lens.size(); i++) {
					//cerr << lens[i] << " ";
					cost += abs(lens[i] - lens[lens.size()/2]); // diff from median
				}
				//cerr << endl;
			}
		}

		if (broken) {
			cout << "Fegla Won";
		} else {
			cout << cost;
		}
		cout << endl;
	}
	return 0;
}

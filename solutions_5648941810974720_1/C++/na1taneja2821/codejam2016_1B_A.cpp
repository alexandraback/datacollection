#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	int run;
	for(run = 1; run <= t; run++) {
		string str;
		string strChar[10];
		strChar[0] = "ZERO";
		strChar[1] = "ONE";
		strChar[2] = "TWO";
		strChar[3] = "THREE";
		strChar[4] = "FOUR";
		strChar[5] = "FIVE";
		strChar[6] = "SIX";
		strChar[7] = "SEVEN";
		strChar[8] = "EIGHT";
		strChar[9] = "NINE";
		cin >> str;
		int hash[26] = {0};
		int hash2[10] = {0};
		int i;
		for(i = 0; i < str.size(); i++) {
			hash[str[i] - 'A']++;
		}
		vector<pair<int, char> > order;
		order.push_back(make_pair(0, 'Z'));
		order.push_back(make_pair(2, 'W'));
		order.push_back(make_pair(8, 'G'));
		order.push_back(make_pair(4, 'U'));
		order.push_back(make_pair(6, 'X'));
		order.push_back(make_pair(3, 'H'));
		order.push_back(make_pair(1, 'O'));
		order.push_back(make_pair(7, 'S'));
		order.push_back(make_pair(9, 'N'));
		order.push_back(make_pair(5, 'F'));
		for(i = 0; i < order.size(); i++) {
			int val = order[i].first;
			char ch = order[i].second;
			while(hash[ch - 'A'] > 0) {
				//cout << "Hello";
				hash2[val]++;
				int j;
				for(j = 0; j < strChar[val].size(); j++) {
					//cout << strChar[val][j] << " " << hash[strChar[val][j] - 'A'] << " ";
					hash[strChar[val][j] - 'A']--;
				}
			}
		}
		cout << "Case #" << run << ": ";
		for(i = 0; i < 10; i++) {
			while(hash2[i]) {
				cout << i;
				hash2[i]--;
			}
		}
		cout << endl;
	}
	return 0;
}

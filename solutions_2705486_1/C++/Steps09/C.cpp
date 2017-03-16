#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector <int> vi;

vector <string> dict;

void load_dict() {
	string s;
	ifstream f("garbled_email_dictionary.txt");
	while (f >> s) {
		dict.push_back(s);
	}
	f.close();
	cerr << "Loaded " << dict.size() << " words!" << endl;
}

int match(const string &s, int p, const string &t, int &tn) {
	if (p + t.size() > s.size())
		return -1;

	int r = 0;

	for (int i = 0; i < t.size(); ++i, ++p, --tn)
		if (s[p] != t[i]) {
			if (tn > 0)
				return -1;
			tn = 5;
			++r;
		}

	return r;
}

int mns[4002][5];

int main() {
	load_dict();
	int T;
	cin >> T;
	for (int TT = 1; TT <= T; ++TT) {
		cerr << "Processing " << TT << " word!" << endl;
		string s;
		cin >> s;

		memset(mns, 0, sizeof(mns));

		for (int i = 0; i < 5; ++i)
			mns[s.size()][i] = 0;

		for (int i = s.size() - 1; i >= 0; --i) {
			if (i % 50 == 0)
				cerr << "At pos: " << i << endl;
			for (int j = 0; j < 5; ++j) {
				int mn = 5000;
				for (int t = 0; t < dict.size(); ++t) {
					int tno = j;
					int k = match(s, i, dict[t], tno);
					tno = max(0, tno);

					if (k != -1 && mns[i + dict[t].size()][tno] != -1) {
						mn = min(mn, k + mns[i + dict[t].size()][tno]);
					}
				}
				mns[i][j] = mn == 5000 ? -1 : mn;
			}
		}

		printf("Case #%d: %d\n", TT, mns[0][0]);

		cerr << clock() << endl;
	}

	cerr << clock() << endl;
}
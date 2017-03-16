#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string reformat(string s) {
	string res = s.substr(0, 1);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			res += s[i];
		}
	}

	return res;
}

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small.out", "w+", stdout);
	cin >> T;

	
	for (int cas = 1; cas <= T; cas++){
		int N = 0;
		cin >> N;

		int sz = 0;
		vector <string> lab;
		vector <int> perm;
		for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;
			tmp = reformat(tmp);
			lab.push_back(tmp);

			perm.push_back(i);
			sz += tmp.size();
		}

		int res = 0;
		do {
			int occur[256] = {0};
			bool ava = true;
			occur[lab[perm[0]][0]] = 1;
			char prev = lab[perm[0]][0];
			
			for (int i = 0; i < N && ava; i++) {
				for (int pos = 0; pos < lab[perm[i]].size(); pos++) {
					char curr = lab[perm[i]][pos];
					if (occur[curr] == 1) {
						if (curr != prev) {
							ava = false;
							break;
						}
					} else {
						occur[curr] = 1;
					}

					prev = curr;
				}
			}

			if (ava) {
				res++;
				//				cerr << "av " << sum << endl;
			} else {
				//				cerr << "na " << sum << endl;
			}
		} while (next_permutation(perm.begin(), perm.end()));

		cout << "Case #" << cas << ": " << res << endl;
	}
    return 0;
}

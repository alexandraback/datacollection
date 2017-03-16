#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define puba push_back

using namespace std;

int t, n;
string s;

int main() {
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		cin >> n;
		vector <string> v;
		vector <int> vi;
		for (int j = 0; j < n; ++j) {
			cin >> s;
			//cout << s << endl;
			v.puba(s);
			vi.puba(j);
		}
		int ans = 0;
		do {
			string ns = "";
			for (int j = 0; j < n; ++j) {
				ns += v[vi[j]];
			}
			//cout << ns << endl;
			bool used[26];
			memset(used, 0, sizeof used);
			used[ns[0] - 'a'] = true;
			bool flag = true;
			for (int j = 1; j < (int) ns.size(); ++j) {
				if (used[ns[j] - 'a'] && ns[j - 1] != ns[j]) {
					flag = false;
					break;
				}
				used[ns[j] - 'a'] = true;
			}
			if (flag) {
				//cout << "+" << endl;
				++ans;
			}
		} while(next_permutation(vi.begin(), vi.end()));
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}

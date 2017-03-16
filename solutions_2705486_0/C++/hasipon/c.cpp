#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<string> dict[11];
string S;
map<pair<int,int>, int> memo;
int f(int p, int q) {
	if (p == (int)S.length()) return 0;
	if (memo.count(make_pair(p,q))) return memo[make_pair(p,q)];
	int r = 1<<29;
	for (int len = 1; len <= 10 && p+len <= (int)S.length(); ++ len) {
		map<int,int> x;
		for (unsigned i = 0; i < dict[len].size(); ++ i) {
			int k = q;
			int c = 0;
			for (int j = 0; j < len; ++ j) {
				if (S[p+j] != dict[len][i][j]) {
					if (p+j < k+5) goto next;
					k = j;
					++ c;
					if (x.count(k) && c >= x[k]) goto next;
				}
			}
			x[k] = c;
			next:;
		}
		for (map<int,int>::iterator it = x.begin(); it != x.end(); ++ it) {
			r = min(r, f(p+len, it->first) + it->second);
		}
	}
	return memo[make_pair(p,q)] = r;
}
int solve() {
	cin >> S;
	memo.clear();
	return f(0, -5);
}
int main(int argc, char** argv) {
	ifstream in("garbled_email_dictionary.txt");
	string buf;
	while (in >> buf) {
		dict[buf.length()].push_back(buf);
	}
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt+atoi(argv[1]) << ": " << solve() << endl;
	}
}

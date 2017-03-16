#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

bool check_str(const string& s) {
	bool bch[26] = {};
	bch[s[0] - 'a'] = true;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i] && bch[s[i] - 'a'])
			return false;
		bch[s[i] - 'a'] = true;
	}
	return true;
}

bool check_strlist(const vector<string>& vs) {
	for (const string& s : vs) {
		if (!check_str(s))
			return false;
	}
	return true;
}

bool gen_next_symbols(const vector<string>& vs, char next[26]) {
	fill(next, next + 26, -1);
	char prev[26];
	fill(prev, prev + 26, -1);
	for (auto ts : vs) {
		for (int i = 1; i < ts.length(); i++) {
			if (ts[i] != ts[i - 1]) {
				if (prev[ts[i] - 'a'] != char(-1) || next[ts[i - 1] - 'a'] != char(-1))
					return false;
				next[ts[i - 1] - 'a'] = ts[i] - 'a';
				prev[ts[i] - 'a'] = ts[i - 1] - 'a';
			}
		}
	}
	return true;
}

long long factorial(int n) {
	long long r = 1;
	while (n > 0) {
		r = (r * n) % MOD;
		n--;
	}
	return r;
}

bool find_cycle(char next[26]) {
	for (int i = 0; i < 26; i++) {
		bool f[26] = {};
		int j = i;
		while (j != char(-1)) {
			if (f[j]) return true;
			f[j] = true;
			j = next[j];
		}
	}
	return false;
}

int main() {
	ifstream fin("B-large.in");
	ofstream fout("out.txt");
	istream& in = fin;
	ostream& out = fout;
	
	int T;
	in >> T;
	long long res;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n;
		in >> n;
		vector<string> s(n);
		for (int i = 0; i < n; i++)
			in >> s[i];

		char next[26];
		if (check_strlist(s) && gen_next_symbols(s, next) && !find_cycle(next)) {
			int k = 0;
			bool bch[26] = {};
			for (auto ts : s) {
				for (auto ch : ts) {
					if (!bch[ch - 'a']) {
						bch[ch - 'a'] = true;
						k++;
					}
				}
			}

			for (int i = 0; i < 26; i++) {
				if (next[i] != char(-1))
					k--;
			}

			res = factorial(k);
			
			for (int i = 0; i < 26; i++) {
				int ck = 0;
				for (auto ts : s) {
					if (ts[0] - 'a' == i && *ts.rbegin() - 'a' == i)
						ck++;
				}
				res = (res * factorial(ck)) % MOD;
			}
		} else
			res = 0;

		out << "Case #" << test_case << ": " << res << endl;
	}

	out.flush();
	return 0;
}

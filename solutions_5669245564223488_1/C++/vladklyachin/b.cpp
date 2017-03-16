#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

#define MOD 1000000007
#define NN 200

int64_t fact[NN+1];

void mult(int64_t & a, int64_t b) {
	a = (a*b)%MOD;
}

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: infile outfile\n";
		return 1;
	}
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << argv[1] << ": " << strerror(errno) << endl;
		return 1;
	}
	ofstream fo(argv[2]);
	if (!fo) {
		cerr << argv[2] << ": " << strerror(errno) << endl;
		return 1;
	}

	fact[0] = 1;
	for (int i = 1; i <= NN; ++i) {
		fact[i] = (fact[i-1]*i)%MOD;
	}

	int T;
	fi >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		fi >> N;
		string s;
		vector<int> internals(26);
		vector<int> first(26, -1);
		vector<int> second(26, -1);
		vector<int> singles(26);
		vector<int> used(26);
		vector<string> strings(N);
		int64_t prod = 1;
		int nSets = 0;
		for (int n = 0; n < N; ++n) {
			fi >> strings[n];
		}
		for (int n = 0; n < N; ++n) {
			s = strings[n];
			char c0 = s[0];
			char cl = s[s.size()-1];
			if (c0 == cl) {
				for (size_t i = 1; i < s.size()-1; ++i) {
					if (s[i] != c0) goto failed;
				}
				++singles[c0-'a'];
				continue;
			}
			if (second[c0-'a'] >= 0 || first[cl-'a'] >= 0) goto failed;
			int x = 1;
			while (s[x] == c0) ++x;
			int y = s.size()-2;
			while (s[y] == cl) --y;
			while (x <= y) {
				char cx = s[x];
				while (x <= y && s[x] == cx) ++x;
				if (internals[cx-'a']) goto failed;
				internals[cx-'a'] = 1;
			}
			second[c0-'a'] = cl-'a';
			first[cl-'a'] = c0-'a';
		}
		// check internal letters
		for (int i = 0; i < 26; ++i) {
			if (singles[i] > 0 && internals[i]) goto failed;
			if (second[i] >= 0 && (internals[i] || internals[second[i]])) goto failed;
		}
		// divide for disjoint sets
		for (int i = 0; i < 26; ++i) {
			if (!used[i] && first[i] < 0 && second[i] >= 0) {
				for (int j = i; j >= 0; j = second[j]) {
					mult(prod, fact[singles[j]]);
					used[j] = 1;
				}
				++nSets;
			}
		}
		// check for cycles and add singles
		for (int i = 0; i < 26; ++i) {
			if (!used[i]) {
			   	if (first[i] >= 0 || second[i] >= 0) {
					goto failed;
				}
				if (singles[i] > 0) {
					mult(prod, fact[singles[i]]);
					++nSets;
				}
			}
		}
		mult(prod, fact[nSets]);
		fo << "Case #" << t << ": " << prod << endl;
		continue;
failed:
		fo << "Case #" << t << ": 0\n";
	}
}

/* vim: set ts=4 sw=4 noet: */

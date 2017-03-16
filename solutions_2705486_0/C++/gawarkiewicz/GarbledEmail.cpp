#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

vector<string> dict;
int best;
vector<vector<int>> mem;
map<char, int> beg;

int isok(const string& S, int from, int ok, const string& word, int& wrongCnt) {
	wrongCnt = 0;
	if (word.size() > S.size()-from) return -1;
	for (int i=0; i<word.size(); ++i) {
		if (ok < 4 && word[i] != S[from+i]) {
			return -1;
		}
		if (word[i] == S[from+i]) {
			++ok;
		}
		else {
			ok = 0;
			wrongCnt++;
		}
	}
	return min(ok, 4);
}

int solve(const string& S, int from=0, int ok = 4, int curres = 0) {
	if (curres >= best) return 10000;
	if (from == S.size()) {
		best = curres;
		return 0;
	}
	ok = min(ok, 4);
	int& ret = mem[from][ok];
	if (ret < 1000000) return ret;
	ret = 10000;
	for (int i=(ok>=4?0:beg[S[from]]); i<dict.size(); ++i) {
		if (ok < 4 && dict[i][0] != S[from]) break;
		int cur = 0;
		int newok = isok(S, from, ok, dict[i], cur);
		if (newok > -1) {
			int s = solve(S, from+dict[i].length(), newok, cur+curres);
			if (s + cur < ret) ret = s+cur;
		}
	}
	return ret;
}

int main() {
	dict.resize(521196);
	ifstream in("C:\\Dane\\profil\\Documents\\konkursy\\2013 Google Code Jam\\Round 1B\\Release\\garbled_email_dictionary.txt");
	for (int i=0; i<dict.size(); ++i) {
		in >> dict[i];
		int &t = beg[dict[i][0]];
		if (t == 0) t = i;
	}
	beg['a'] = 0;

	int T;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cerr << t << endl;
		string S;
		cin >> S;
		best = 10000;
		mem.clear();
		mem.resize(S.length()+1);
		for (int i=0; i<mem.size(); ++i) mem[i].resize(5, 2000000);
		cout << "Case #" << t << ": " << solve(S) << endl;
	}
	return 0;
}
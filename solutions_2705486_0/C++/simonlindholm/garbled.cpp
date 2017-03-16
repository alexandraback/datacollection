#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int LIM = 5;
int N;

vector<string> shortWords;
map<string, vector<string> > longWords;
string Word;
vector<vector<int> > dp;

vector<vector<double> > mem(2000, vector<double>(2000, -2));
double prob(int rem, int remRight) {
	if (remRight <= 0)
		return 1;
	if (remRight > rem)
		return 0;
	double& res = mem[rem][remRight];
	if (res > -1)
		return res;
	return res = (prob(rem-1, remRight) + prob(rem-1, remRight-1)) / 2;
}

void tryWord(int ind, int left, string& word) {
	int sz = (int)word.size();
	if (ind + sz > N)
		return;
	int wrong = 0, nleft = left;
	for (int i = 0; i < sz; ++i) {
		if (word[i] != Word[ind + i]) {
			if (nleft)
				return;
			nleft = LIM;
			++wrong;
		}
		if (nleft)
			--nleft;
	}
	int res = dp[ind + sz][nleft] + wrong;
	dp[ind][left] = min(dp[ind][left], res);
}

void step(int ind, int left) {
	for (string& s : shortWords) {
		tryWord(ind, left, s);
	}

	if (ind + LIM > N)
		return;
	string w = Word.substr(ind, LIM);
	for (int whichtochange = left; whichtochange < LIM; ++whichtochange) {
		char orig = w[whichtochange];
		for (char c = 'a'; c <= 'z'; ++c) {
			w[whichtochange] = c;
			map<string, vector<string> >::iterator it = longWords.find(w);
			if (it != longWords.end()) {
				vector<string>& possible = it->second;
				for (string& s : possible) {
					tryWord(ind, left, s);
				}
			}
		}
		w[whichtochange] = orig;
	}
}

int solve() {
	string str;
	cin >> str;
	Word = str;
	N = (int)str.size();
	dp.assign(N+1, vector<int>(LIM, 1 << 30));
	for (int i = 0; i < LIM; ++i)
		dp[N][i] = 0;

	for (int i = N; i --> 0; ) {
		for (int left = 0; left < LIM; ++left) {
			step(i, left);
		}
	}
	return dp[0][0];
}

int main() {
	string word;
	ifstream fin("garbled_email_dictionary.txt");
	while (getline(fin, word)) {
		if ((int)word.size() < LIM)
			shortWords.push_back(word);
		else
			longWords[word.substr(0, LIM)].push_back(word);
	}
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
}

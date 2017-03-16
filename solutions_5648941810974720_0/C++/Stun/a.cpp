#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

#include <unordered_map>
#include <sstream>

using namespace std;

vector<vector<string>> spells = {
	{"ZERO", "0"}, // Z
	{"TWO", "2"}, // W
	{"FOUR", "4"}, // U
	{"ONE", "1"}, // O
	{"SIX", "6"}, // X
	{"EIGHT", "8"}, // G
	{"SEVEN", "7"}, // S
	{"FIVE", "5"}, // V
	{"THREE", "3"}, // R
	{"NINE", "9"}};

unordered_map<char, int> M;

bool exist(const string & t) {
	unordered_map<char, int> X;
	bool fail = false;;
	for (int i = 0 ; i < t.size() ; ++i) {
		if (M.count(t[i]) == 0 || M.at(t[i]) == 0) {
			fail = true;
			break;
		}
		if (X.count(t[i]) == 0)
			X[t[i]] = 0;
		X[t[i]]++;
		M[t[i]]--;
	}
	if (fail) {
		for (const auto & p : X) 
			M[p.first] += p.second;
		return false;
	}

	return true;
}

string solve(const string & S) {
	M.clear();
	for (int i = 0 ; i < S.size() ; ++i) {
		if (M.count(S[i]) == 0)
			M[S[i]] = 0;
		M[S[i]]++;
	}

	stringstream ss;
	for (int i = 0 ; i < spells.size() ; ++i) {
		if (exist(spells[i][0])) {
			ss << spells[i][1];
			--i;
		}
	}
	return ss.str();
}

int main(){
	int tcase;
	cin >> tcase;

	string S;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{

		cin >> S;
		
		cout << "Case #" << casen + 1 << ": ";
		auto s = solve(S);
		std::sort(s.begin(), s.end());
		cout << s << endl;
		
	}
	

	return 0;
}

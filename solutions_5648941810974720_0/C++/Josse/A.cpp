#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <cctype>

using namespace std;

char l[] = {'Z', 'W', 'U', 'X', 'G', 'H', 'F', 'S', 'O', 'E'};
int n[]  = { 0 ,  2 ,  4 ,  6 ,  8 ,  3 ,  5 ,  7 ,  1 ,  9 };

string digits[] = {"ZERO",
                   "ONE",
                   "TWO",
                   "THREE",
                   "FOUR",
                   "FIVE",
                   "SIX",
                   "SEVEN",
                   "EIGHT",
                   "NINE"};

string solve() {
	map<char,int> telLetters;
	string str;
	cin >> str;
	assert(str.size() >= 3 && str.size() <= 2000);
	for (string::iterator it = str.begin(); it != str.end(); it++) {
		assert(isupper(*it));
		telLetters[*it]++;
	}
	int telCijfers[10] = {0};
	for (int i = 0; i < 10; i++) {
		int k = telLetters[l[i]];
		assert(k >= 0);
		telCijfers[n[i]] = k;
		for (string::iterator it = digits[n[i]].begin(); it != digits[n[i]].end(); it++) {
			telLetters[*it] -= k;
			assert(telLetters[*it] >= 0);
		}
	}
	for (char check = 'A'; check <= 'Z'; check++) {
		map<char,int>::iterator it = telLetters.find(check);
		assert(it == telLetters.end() || it->second == 0);
	}
	string ret;
	for (int i = 0; i < 10; i++) {
		while (telCijfers[i]--)
			ret.push_back('0' + i);
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}

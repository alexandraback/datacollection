#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()

bool isvowel(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
		return true;
	}
	else return false;
}


int main() {
	int T, c, i, n, res;
	fin >> T;
	string S;
	vi X0, count;

	for (c = 1; c <= T; c++) {
		fin >> S >> n;

		X0.resize(sz(S), 0);
		count.resize(sz(S), 0);

		if (isvowel(S[0])) count[0] = 0;
		else count[0] = 1;
		if (n == 1 && count[0] == 1) X0[0] = 0;
		else X0[0] = -1;

		for (i = 1; i < sz(S); i++) {
			count[i] = count[i-1];
			if (!isvowel(S[i])) count[i]++;
			if (i - n >= 0) {
				if (!isvowel(S[i-n])) count[i]--;
			}
			if (count[i] == n) {
				X0[i] = i-n+1;
			}
			else {
				X0[i] = X0[i-1];
			}
		}

		res = 0;
		for (i = 0; i < sz(S); i++) {
			if (X0[i] == -1) continue;
			else {
				res += X0[i] + 1;
			}
		}

		fout << "Case #" << c <<": " << res << endl;
	}

	return 0;
}

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXN = 2000;
map<string, int> str2int;
int nStrings;

bool connected[MAXN][MAXN];
bool inFirst[MAXN];
bool inSecond[MAXN];

int findInd(string s) {
	if (str2int.find(s) == str2int.end()) {
		str2int[s] = nStrings++;
		return nStrings - 1;
	}
	else {
		return str2int[s];
	}
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	/*
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	*/

	/*
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	*/

	/*
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	*/
	int nCases;
	cin >> nCases;

	for (int i = 1; i <= nCases; i++) {
		cout << "Case #" << i << ": ";

		nStrings = 0;
		str2int.clear();
		memset(connected, 0, sizeof(connected));
		memset(inFirst, 0, sizeof(inFirst));
		memset(inSecond, 0, sizeof(inSecond));

		int nPairs;
		cin >> nPairs;

		int result = 0;
		while (nPairs--) {
			string s1, s2;
			cin >> s1 >> s2;

			int n1 = findInd(s1);
			int n2 = findInd(s2);

			connected[n1][n2] = true;
			inFirst[n1] = true;
			inSecond[n2] = true;
		}

		for (int i = 0; i < nStrings; i++) {
			if (inFirst[i]) {
				for (int j = 0; j < nStrings; j++) {
					if (i != j && inSecond[j] && !connected[i][j]) {
						result++;
					}
				}
			}
		}

		cout << result;

		cout << endl;
	}

	return 0;
}
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <iostream>
#include <cfloat>
#include <ctime>
#include <sstream>
using namespace std;
#define all(a) a.begin(),a.end()
#define mset(a, v) memset(a, v, sizeof(a));
typedef long long ll;
#pragma comment(linker, "/STACK:268435456")

string L;
int N;

bool isVowel(char c) {
	return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
}

ll solve(int currIndex, int lastOkIndex, int consequtive) {
	// Update the OK Index.
	if (!isVowel(L[currIndex])) {
		++consequtive;
	} else {
		consequtive = 0;
	}

	if (consequtive >= N) {
		lastOkIndex = currIndex - N + 1;
	}

	if (currIndex + 1 < (int)L.size()) {
		return solve(currIndex + 1, lastOkIndex, consequtive) + lastOkIndex + 1;
	}
	return lastOkIndex + 1;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> L >> N;

		cout << solve(0, -1, 0) << endl;
	}

	return 0;
}

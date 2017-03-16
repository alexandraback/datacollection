#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)

#include <cassert>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for (int i=0; i<(E); i++)

typedef long long ll;
//const ll MOD = 1000000007;
//const double PI = atan(1) * 4;







char s[1003];
int N;


string solve(int len) {
	if (len == 0) return "";


	char maxC = s[0];
	int maxI = 0;
	FOR(i, len) if (maxC < s[i]) {
		maxC = s[i];
		maxI = i;
	}

	string maxStr;
	string others;
	for (int i=maxI; i<len; i++) {
		if (s[i] == maxC)
			maxStr.push_back(s[i]);
		else
			others.push_back(s[i]);
	}

	
	return maxStr + solve(maxI) + others;
}





int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC; cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);
		
		cin >> s;
		N = strlen(s);

		cout << solve(N) << endl;
	}


	return 0;
}

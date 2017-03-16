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



char s[133];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC; cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);

		cin >> s;
		int i = strlen(s);
		s[i] = '+';
		i--;


		int cnt = 0;
		for (; i>=0; i--) {
			cnt += s[i] != s[i+1];
		}

		cout << cnt << endl;


	}


	return 0;
}

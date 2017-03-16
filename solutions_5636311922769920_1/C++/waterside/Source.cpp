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






int K, C, S;

int main() {
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC; cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);

		cin >> K >> C >> S;
		if (S*C < K) {
			puts("IMPOSSIBLE");
			continue;
		}





		ll idx = 0;

		for (int i=0; i<K; i++) {
			idx = idx*K + i;
			
			if (i%C==C-1 || i==K-1) {
				cout << idx+1 << " ";
				idx = 0;
			}
		}
		cout << endl;
	}


	return 0;
}
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




int cnt;
bool appeared[10];
void check(ll num) {
	if (num == 0) return;


	if (appeared[num%10] == false) {
		appeared[num%10] = true;
		cnt++;
	}

	check(num/10);
}



int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC; cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);


		ll num; cin >> num;
		if (num == 0) {
			puts("INSOMNIA");
			continue;
		}


		MEMSET(appeared, 0);
		cnt = 0;

		ll n = num;
		check(n);
		while (cnt != 10) {
			n += num;
			check(n);
		}

		cout << n << endl;

	}


	return 0;
}

#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

bool us[10];

int add(ll x) {
	if (x == 0) {
		return 0;
	}

	while (x != 0) {
		us[x % 10] = 1;
		x /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (us[i] == false) {
			return 0;
		}
	}

	return 10;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;
	int f = 0;

	while (t--) {
		f++;
		memset(us, 0, sizeof us);
		cout << "Case #" << f << ": "; 
		
		char s[110];

		scanf("%s", s);

		char c = s[0];

		int len = strlen(s);

		int cnt = 0;

		for (int i = 1; i < len; i++) {
			if (s[i] != c) {
				c = s[i];
				cnt++;
			}
		}

		if (c == '-') {
			cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}

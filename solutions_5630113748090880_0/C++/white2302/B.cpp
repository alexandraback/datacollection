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
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

int cnt[2550];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;
	int f = 0;

	while (t--) {
		f++;
		cout << "Case #" << f << ": ";

		int n;

		cin >> n;

		memset(cnt, 0, sizeof cnt);

		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int x;

				scanf("%d", &x);

				cnt[x]++;
			}
		}

		vector <int> ans;

		for (int i = 0; i < 2550; i++) {
			if (cnt[i] % 2 == 1) {
				ans.push_back(i);
			}
		}

		for (int i = 0; i < (int)ans.size(); i++) {
			printf("%d ", ans[i]);
		}

		if (ans.size() != n) {
			throw 1;
		}

		cout << endl;
	}

	return 0;
}

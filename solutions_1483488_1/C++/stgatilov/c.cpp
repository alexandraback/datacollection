#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 2<<20;

int a, b;
bool used[SIZE];
int cnt[SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d%d", &a, &b);
		memset(used, 0, sizeof(used));
		memset(cnt, 0, sizeof(cnt));

		for (int x = a; x<=b; x++) {
			if (used[x]) continue;

			char str[16];
			sprintf(str, "%d", x);
			int l = strlen(str);

			int csz = 0;
			for (int j = 0; j<l; j++) {
				if (str[0] != '0') {
					int curr;
					assert(sscanf(str, "%d", &curr) == 1);
					if (curr >= a && curr <= b && !used[curr]) {
						used[curr] = true;
						csz++;
					}
				}
				rotate(str, str+1, str+l);
			}

			cnt[x] = csz;
		}

		int ans = 0;
		for (int x = a; x<=b; x++) {
			int c = cnt[x];
			if (c) ans += c * (c-1) / 2;
		}

		printf("Case #%d: %d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}

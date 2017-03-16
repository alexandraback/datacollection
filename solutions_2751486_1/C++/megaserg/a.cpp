#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long int64;
typedef long double ldouble;

#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)

#define PROBLEM "A"

const int MAXN = 1 << 20;

string s;
int n, m;

bool a[MAXN];

bool vowel(char c) {
	return c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u';
}

int64 sum(int64 a, int64 b) {
	return (b - a + 1ll) * (b + 1ll) - (b * (b+1) - a * (a-1)) / 2ll;
}

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        cin >> s >> m;
        n = s.length();

        memset(a, 0, sizeof a);

        for (int i = 0; i < n; i++) {
        	if (vowel(s[i])) {
        		a[i] = 0;
        	}
        	else {
        		a[i] = 1;
        	}
        }

        int64 cur = 0;
        int64 ans = 0;
        int64 i0 = 0, i1 = -1, i2 = 0, i3 = n;

		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				if (cur == 0) i1 = i;
				cur++;
			}
			else {
				if (cur > 0 && cur >= m) {
					assert(i1 != -1);

					i0 = max(i2-m+1, 0ll);
					i2 = i;

					int64 s1 = (i1 - i0) * (i3 - (i1 + m) + 1ll);
					int64 s2 = (i2 - m - i1 + 1ll) * (i3 - i2);
					int64 s3 = sum(m, i2 - i1);

					ans += s1 + s2 + s3;
				}
				cur = 0;
			}
		}

		if (cur > 0 && cur >= m) {
			assert(i1 != -1);

			i0 = max(i2-m+1, 0ll);
			i2 = n;

			int64 s1 = (i1 - i0) * (i3 - (i1 + m) + 1ll);
			int64 s2 = (i2 - m - i1 + 1ll) * (i3 - i2);
			int64 s3 = sum(m, i2 - i1);

			ans += s1 + s2 + s3;
   		}

		cout << ans;

        printf("\n");
    }

    return 0;
}

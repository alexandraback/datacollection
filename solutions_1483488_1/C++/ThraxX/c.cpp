#include <vector>

#include <string>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <cstring>

#include <map>
#include <set>

#include <cassert>

#include <numeric>
#include <bitset>

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex>
#include <cstdlib>

#include <list>
#include <deque>
#include <queue>
#include <stack>

#include <functional>
#include <cctype>
#include <ctime>

using namespace std;
typedef long long ll;

#define fill(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(s,container) for (typeof((container).begin()) s = (container).begin(); s != (container).end(); s++)

int len[2000001];
int pw[9];

int main() {
    for (int i = 1; i < 2000001; ++i)
        len[i] = len[i / 10] + 1;
    pw[0] = 1;
    for (int i = 1; i < 9; ++i)
        pw[i] = pw[i - 1] * 10;
	int t, tCtr;
	scanf("%d", &t);
	for (tCtr = 0; tCtr < t; ++tCtr) {
        int a, b, ans = 0;
        scanf("%d %d", &a, &b);
        for (int n = a; n <= b; ++n) {
            int l = len[n];
            set <int> q;
            for (int r = 1; r < l; ++r) {
                if ((n / pw[r - 1]) % pw[1] == 0)
                    continue;
                int m = n / pw[r] + pw[l - r] * (n % pw[r]);
                if (a <= n && n < m && m <= b) {
                    q.insert(m);
                }
            }
            ans += q.size();
        }
	
		printf("Case #%d: ", tCtr + 1);
        printf("%d\n", ans);
	}
	return 0;

}


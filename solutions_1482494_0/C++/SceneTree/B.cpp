#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

int n, a[2005], b[2005], c[2005];

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    int Tests, tts = 0;
    for (scanf("%d", &Tests); Tests--; ) {
        printf("Case #%d: ", ++tts);

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            c[i] = 2;
        }

        int now = 0, ans = 0;
        for (int o = 1; o <= n + n; ++o) {
            int tnow = now, ch = -1;
            for (int i = 1; i <= n; ++i)
            if (c[i] > 0) {
                if (b[i] <= now) {
                    ch = i;
                    break;
                } else if (a[i] <= now && c[i] >= 2) {
                    if (ch == -1 || b[i] > b[ch]) ch = i;
                }
            }

            if (ch == -1) break;
            ++ans;
            if (b[ch] <= now) {
                now += c[ch];
                c[ch] = 0;
            } else {
                ++now;
                c[ch]--;
            }
            if (now == tnow) break;
        }

        bool sol = 1;
        for (int i = 1; i <= n; ++i) if (c[i] > 0) sol = 0;
        if (!sol) puts("Too Bad"); else printf("%d\n", ans);
    }
    return 0;
}

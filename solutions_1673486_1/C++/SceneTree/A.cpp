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

int n, m;
double s[100005], a[100005];
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int Tests, tts = 0;
    for (scanf("%d", &Tests); Tests--; ) {
        scanf("%d%d", &n, &m);
        s[0] = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf", &a[i]);
            s[i] = s[i - 1] * a[i];
        }

        double ans = m + 2;
        for (int i = 0; i <= n; ++i) {
            int t = m - n + i + i + 1;
            double now = t * s[n - i] + (t + m + 1) * (1 - s[n - i]);
            ans = min(ans, now);
        }
        printf("Case #%d: %.6lf\n", ++tts, ans);
    }
    return 0;
}

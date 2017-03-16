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

const int maxn = 10;

int n;
int w[maxn];
double v[maxn], p[maxn], ans;

    void dfs(double tm, double la)
    {
        if (ans < 0) return;
        double mn = -1;
        int x, y;
        //for (int i = 1; i <= n; ++i) printf("%d %.2lf %.2lf\n", w[i], v[i], p[i]);

        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        if (i != j && w[i] == w[j])
        if (p[i] < p[j] && v[i] > v[j]) {
            double t = (p[j] - p[i] - 5) / (v[i] - v[j]);
            if (mn < 0 || t < mn) {
                mn = t;
                x = i;
                y = j;
            }
        }
        if (mn < 0) {
            ans = -1;
            return;
        }
        if (abs(mn) < eps && abs(la) < eps) return;
        //printf("******************** %d %d %.6lf %.6lf\n", x, y, mn, tm);
        ans = max(ans, tm + mn);
        for (int i = 1; i <= n; ++i) p[i] += v[i] * mn;
        bool ff = 1;
        for (int i = 1; i <= n; ++i)
        if (w[i] != w[x] && abs(p[i] - p[x]) < 5) { ff = 0; break; }
        if (ff) { w[x] ^= 1; dfs(tm + mn, mn); w[x] ^= 1; }
        ff = 1;
        for (int i = 1; i <= n; ++i)
        if (w[i] != w[y] && abs(p[i] - p[y]) < 5) { ff = 0; break; }
        if (ff) { w[y] ^= 1; dfs(tm + mn, mn); w[y] ^= 1; }
        for (int i = 1; i <= n; ++i) p[i] -= v[i] * mn;
    }

int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
    int Tests, tts = 0;
    for (scanf("%d", &Tests); Tests--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            char s[5];
            scanf("%s%lf%lf", s, &v[i], &p[i]);
            if (s[0] == 'L') w[i] = 0;
            else w[i] = 1;
        }
        printf("Case #%d: ", ++tts);
        if (n <= 2) puts("Possible");
        else {
            ans = 0;
            dfs(0, -1);
            if (ans < 0) puts("Possible");
            else printf("%.6lf\n", ans);
        }
    }
    return 0;
}

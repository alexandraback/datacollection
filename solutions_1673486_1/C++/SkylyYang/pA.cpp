#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//by Skyly

typedef long long int64;

#define SIZE(X) ((int)((X).size())) 
#define FOR(IT, X) for (__typeof((X).begin()) IT = (X).begin(); IT != (X).end(); ++IT)

template<typename T> string toStr(const T &x) { ostringstream os; os << x; return os.str(); }
template<typename T> void toMin(T &x, const T &y) { x = min(x, y); }
template<typename T> void toMax(T &x, const T &y) { x = max(x, y); }

const int MAXN = 100005;

int A, B;
double pr[MAXN];
double dp[MAXN];

int main() {
    int t;
    double ans;

    scanf("%d", &t);
    for (int casN = 1; casN <= t; ++casN) {
        scanf("%d%d", &A, &B);
        for (int i = 1; i <= A; i++) {
            scanf("%lf", &pr[i]);
        }
        dp[0] = 0.0;
        for (int i = 1; i <= A; i++) {
            dp[i] = (1.0 - dp[i - 1]) * (1.0 - pr[i]);
            dp[i] += dp[i - 1];
        }
        ans = 1.0 + B;
        for (int i = 0; i <= A; i++) {
            ans = min(ans, (1.0 - dp[A - i]) * (i + i + B - A) + dp[A - i] * (i + i + B - A + 1.0 + B));
        }
        printf("Case #%d: %.9f\n", casN, ans + 1.0);
    }

    return 0;
}


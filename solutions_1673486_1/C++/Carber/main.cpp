#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, char> PIC;
typedef pair<int, int>  PII;
#define MP make_pair

const int INF = 0x3f3f3f3f;

const int MAXN = 100010;
double p[MAXN];
int T, A, B;

double clac1() {
    double pl = 1;
    for (int i = 0; i < A; ++i) {
        pl *= p[i];
    }
    //cout << (B + 1 + B - A + 1) << endl;
    //cout << (B + 1 + B - A + 1) * (1 - pl) << endl;
    //cout << (B - A + 1) << endl;
    return pl * (B - A + 1) + (B + 1 + B - A + 1) * (1 - pl);
}

double clac2() {
    double pl = 1, ans = 1e100;
    for (int i = 0; i < A; ++i) {
        //cout << (B - i + 1 + A - i) << endl;
        //cout << (B + 1 + B - A + 1 + A - i + 1)  << endl;
        //cout << pl * (B - i + 1 + A - i) + (B + 1 + B - A + 1 + A - i) * (1 - pl) << endl;
        ans = min(ans, pl * (B - i + 1 + A - i) + (B + 1 + B - A + 1 + A - i + 1) * (1 - pl));
        pl *= p[i];
    }
    return ans;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        scanf("%d %d", &A, &B);
        for (int i = 0; i < A; ++i) {
            scanf("%lf", &p[i]);
        }
        double ans = B + 2;
        ans = min(ans, clac1());
        ans = min(ans, clac2());
        printf("Case #%d: %.6lf\n", cas, ans);
    }
    return 0;
}
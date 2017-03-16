#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
#define MP make_pair

const int MAXN = 256;
double sum, ar[MAXN];
int N;

double solved(int index, double low, double high) {
    while (high - low > 1e-10) {
        double mid = (high + low) / 2.0;
        double tmp = ar[index] + sum * mid;
        double sp = mid;
        bool flag = true;
        for (int i = 0; flag && i < N; ++i) {
            if (i == index || ar[i] > tmp) continue;
            sp += (tmp - ar[i]) / sum;
            if (sp > 1.0) flag = false;
        }
        if (flag) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int nCase; scanf("%d", &nCase);
    for (int tCase = 1; tCase <= nCase; ++tCase) {
        scanf("%d", &N); sum = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%lf", &ar[i]);
            sum += ar[i];
        }
        printf("Case #%d:", tCase);
        for (int i = 0; i < N; ++i) {
            printf(" %.10lf", 100.0 * solved(i, 0, 1));
        } puts("");
    }
    return 0;
}
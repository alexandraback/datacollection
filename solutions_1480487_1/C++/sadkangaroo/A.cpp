#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
#include<climits>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;

const int MaxN = 200 + 5;

int T, N;
double a[MaxN];
double X;

bool check(int now, double p) {
   double score = X * p + a[now]; 
   double cnt = 1 - p;
   for (int i = 0; i < N; ++i) if (i != now) {
       if (a[i] < score) {
           cnt -= (score - a[i]) / X;
       }
   }
   return cnt > 0;
}

void solve(int now) {
    double l = 0, r = 100, mid;
    while (r - l > 1e-8) {
        mid = (l + r) / 2;
        if (check(now, mid / 100.0)) l = mid;
        else r = mid;
    }
    printf(" %.7lf", (l + r) / 2);
}

int main() {

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        scanf("%d", &N);
        X = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%lf", a + i);
            X += a[i];
        }
        printf("Case #%d:", te);
        for (int i = 0; i < N; ++i) solve(i);
        puts("");
    }

    return 0;

}


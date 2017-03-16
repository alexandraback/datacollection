#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;

const int N = 201;
const double eps = 1e-9;
int A[N];
double sum;
double ans[N];
int n;

bool ok(double val, int x) {
    double a = A[x] + sum*val;
    double left = 1.0-val;
    for (int i = 0;i < n;i++) {
        if (i == x || A[i] > a-eps) continue;
        left -= (a-A[i])/sum;
        if (left < -eps) return 1;
    }
    return 0;
}
double solve(int x) {
    double lw = 0.0;
    double hi = 1.0;
    while (lw < hi+eps) {
        double mid = (lw+hi)/2;
        if (ok(mid, x)) hi = mid-eps;
        else lw = mid+eps;
    }
    return lw;
}
int main() {
    int cas;
    scanf("%d", &cas);
    for (int ic = 1;ic <= cas;ic++) {
        scanf("%d", &n);
        for (int i = 0;i < n;i++) scanf("%d", &A[i]);
        sum = 0.0;
        for (int i = 0;i < n;i++) sum += A[i];
        for (int i = 0;i < n;i++) {
            ans[i] = solve(i);
        }
        printf("Case #%d:", ic);
        for (int i = 0;i < n;i++) printf(" %lf", ans[i]*100);
        printf("\n");
    }
    return 0;
}

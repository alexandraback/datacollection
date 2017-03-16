#include <iostream>!
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
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
#define fo(i,b) for(int (i) = 0;(i) < (b);++(i))
#define fo2(i,a,b) for(int (i) = (a);(i) < (b);++(i))
#define N 100010
char s1[N];
char s2[N];
char f[N];
int n1[N];
int n2[N];
int A, B;
double p[N];

double solve1()
{
    double p1 = 1;
    int i;
    double ans = 0;
    for(i = 0; i < A; i++) p1 *= p[i];
    ans = (B-A+1) * p1 + (1-p1) * (B+2 + B - A);
    //printf("a1=%.6lf\n", ans);
    return ans;
}
double solve2()
{
    double p1 = 1;
    int i;
    double ans = (A+B+1);
    double a2;
    for(i = 0; i < A - 1; i++) {
        p1 *= p[i];
        a2 = (A-(i+1) + B - (i+1) + 1) * p1 + (B + 1 +A-(i+1) + B - (i+1) + 1) * (1-p1);
        if(a2 < ans) ans = a2;
    }
    //printf("a2=%.6lf\n", ans);
    return ans;
}

double solve3()
{
    return B+2;
}

void solve()
{
    double a1, a2;
    a1 = solve1();
    a2 = solve2();
    if(a1 > a2) a1 = a2;
    a2 = solve3();
    if(a1 > a2) a1 = a2;
    printf("%.6lf\n", a1);
}
int main()
{
    int d;
    int n;
    int a;
    int i;
    int j;
    int ans;
    int t;
    //freopen("in", "r", stdin);    freopen("out", "w", stdout);
    scanf("%d", &t);
    for(i = 1; i <= t; i++) {
        scanf("%d %d", &A, &B);
        for(j = 0; j < A; j++) scanf("%lf", &p[j]);
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

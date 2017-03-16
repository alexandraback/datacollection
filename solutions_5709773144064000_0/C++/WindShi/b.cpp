#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test;
double C, F, X;
double ans;

int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        scanf("%lf%lf%lf", &C, &F, &X);
        ans = X / 2.0;
        double now = 0;
        for (int i = 1; ; i++)
        {
            now += C / (2.0 + (i - 1) * F);
            if (now > ans) break;
            ans = min(ans, now + X / (2.0 + i * F));
        }
        printf("Case #%d: %.10lf\n", uu, ans);
    }
} 

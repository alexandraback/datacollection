#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

double C,F,X;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int cas = 1;
    int T;
    scanf("%d",&T);
    double ans,tmp,now;
    while (T--) {
        scanf("%lf%lf%lf",&C,&F,&X);
        tmp = 0;
        now = 2;
        ans = 1000000000;
        for (int i = 0; i <= 100200; i++) {
            ans = min(ans,tmp + X / now);
            tmp += C / now;
            now += F;
        }
        printf("Case #%d: %.7f\n",cas++,ans);
    }
}

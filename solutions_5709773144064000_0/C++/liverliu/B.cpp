#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
double cost[200005];
double c,f,x;
void init() {
    for(int i=1;i<=200000;i++) {
        cost[i]=c/(f*(i-1)+2.0) + cost[i-1];
    }
}
int main() {
    freopen("/Users/liverliu/Documents/codejam/B-small-attempt0.in","r",stdin);
    freopen("/Users/liverliu/Documents/codejam/B-small-attempt0.out","w",stdout);
    int T=0, cas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%lf%lf%lf",&c,&f,&x);
        init();
        double ans=1e100;
        for(int i=0;i<200000;i++) {
            ans = min(cost[i] + x/(f*i+2.0), ans);
        }
        printf("Case #%d: %.8f\n",++cas, ans);
    }
}

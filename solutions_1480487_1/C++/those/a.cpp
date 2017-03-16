#include<stdio.h>
#include<map>
#include<queue>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int n, a[1000];
double ans[1000];
int main(){
    int ca; scanf("%d",&ca);
    FOE(tt,1,ca){
        scanf("%d",&n);
        FOR(i,0,n) scanf("%d",&a[i]);
        int total = 0, mx = 0;
        FOR(i,0,n) total += a[i];
        FOR(t,0,n){
            double lo=0, hi=100;
            FOR(it,0,500){
                double mid = (lo+hi)/2;
                double x = mid * total + a[t];
                double sum = 0;
                FOR(i,0,n){
                    if (a[i] < x) sum += (x - a[i]) / total;
                }
                if (sum > 1){
                    hi = mid;
                }else{
                    lo = mid;
                }
                ans[t] = mid * 100;
            }
        }
        printf("Case #%d:", tt);
        FOR(i,0,n) printf(" %.7f",ans[i]); puts("");
    }
    return 0;
}

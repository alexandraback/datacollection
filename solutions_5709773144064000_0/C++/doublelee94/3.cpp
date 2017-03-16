#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
#define N 2000005
#define INF 1000000009
typedef long long LL;
double x, c, f;
int main(){
    int t;
    freopen("B-small-attempt2.in","r",stdin);
    freopen("ans.out","w",stdout);
    scanf("%d", &t);
    int num = 1;
    while(t--){
        scanf("%lf%lf%lf", &c, &f, &x);
        double mv = 100000000;
        double tot = 0, tm = 0;
        double n = 0;
        double v;
        while(1){
            v = 2 + n * f;
            tm = x / v;
            if(tot + tm < mv)mv = tot + tm;
            tm = c / v;
            tot += tm;
            n ++;
            if(tot > mv)break;
        }
        printf("Case #%d: ", num++);
        printf("%.7f\n", mv);
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int T, cas;
double c,f,x,v;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        v = 2.0;
        scanf("%lf%lf%lf", &c, &f, &x);
        printf("Case #%d: ", ++cas);
        double t, ans = x/v, base = 0;
        while (true){
            base += c/v;
            t = base;
            v += f;
            t += x/v;
            if (ans>t){
                ans = t;
            }
            else break;
        }
        printf("%.7f\n", ans);
    }
}

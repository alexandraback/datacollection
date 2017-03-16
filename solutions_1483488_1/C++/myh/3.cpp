#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int POW[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};


int check(int p, int a, int b) {
    int q = p, t = 0, ans = 0, x[10];
    while (q > 0) {
        q /= 10;
        ++t;
    }
    q = p;
    for (int i = 1; i < t; ++i) {
        bool flag = false;
        p = (p % POW[t-1])*10 + (p / POW[t-1]);
        for (int i = 0; i < ans; ++i)
         if (x[i] == p) {
             flag = true;
             break;
         }
        if (flag) continue;
        if (q < p && a <= p && p <= b) {
              x[ans] = p;
              ++ans;
        }
    }
    return ans;
} 
    


int main() {
    freopen("myh3.in","r",stdin); 
    freopen("myh3.out","w",stdout);
    int tt, a, b, ans;
    scanf("%d", &tt);
    for (int k = 1; k <= tt; ++k) {
        scanf("%d%d", &a, &b);
        ans = 0;
        for (int i = a; i <= b; ++i) ans += check(i, a, b);
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}

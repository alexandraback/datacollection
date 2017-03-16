#include <iostream>
#include <vector>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)

const int N = 128;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int t, n, s, p, a[N];
    scanf("%d", &t);
    REP(l, t){
        scanf("%d %d %d", &n, &s, &p);
        int res = 0;
        REP(i, n) {
            scanf("%d", &a[i]);
            int v = a[i] / 3, remin = a[i] % 3;
            if(v >= p){
                res ++;
                continue;
            }
            if(remin && v + 1 >= p){
                res ++;
                continue;
            }
            if(remin == 2 && v + 2 >= p && s){
                res ++, s --;
                continue;
            }
            if(remin == 0 && v + 1 >= p && s && v - 1 >= 0){
                res ++, s --;
                continue;
            }
        }
        printf("Case #%d: %d\n", l + 1, res);
    }
    return 0;
}

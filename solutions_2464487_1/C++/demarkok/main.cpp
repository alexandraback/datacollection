#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int t;

LL mas[(int)1e5];
int ms;

void prg(LL radius, LL t, int test){
    int l = 0; int r = 800000000;
    while (r - l > 1){
        int m = (r + l) / 2;
        if ((2*radius + 2*(LL)m - 1) <= (double)t/(double)m)
            l = m;
        else
            r = m;
        //printf("%d %d %lld\n", l, r, 2*(LL)m*(LL)m*((LL)m + 1)*(2*radius - 3) );
    }
    printf("Case #%d: %d\n", test, l);

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    /*for (int i = 1; mas[i - 1] <= (LL)2*1e18; i++, ms++){
        mas[i] = 2*(LL)i*(LL)i*(LL)(i + 1);
        if (mas[i] < mas[i - 1])
            break;
        printf("%d %lld\n",i, mas[i]);

    }
    */

    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        LL r, t;
        scanf("%lld%lld", &r, &t);
        prg(r, t, i + 1);
    }


    return 0;
}

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    int T;
    int X, R, C;
    int a, b;
    freopen("D-small-attempt1.in", "r", stdin);
    freopen("D-small-attempt1.out", "w", stdout);


    scanf(" %d", &T);

    int res;
    for (int cas = 1; cas <= T; cas++) {
        scanf(" %d %d %d", &X, &a, &b);
        R = min(a,b), C = max(a,b);

        if (X > C) {
            res = 0;
        } else {
            if (X == 1) {
                res = 1;
            } else if (X == 2){
                res = (R*C-1)%2;
            } else if (X == 3){
                if (C == 3 ){
                    res = (R==1)?0:1;
                } else {
                    res = (R==3)?1:0;
                }
            } else {
                res = (R>2)?1:0;
            }
        }

        if (res == 0){
            printf("Case #%d: RICHARD\n", cas);
        } else {
            printf("Case #%d: GABRIEL\n", cas);
        }
    }



    return 0;
}

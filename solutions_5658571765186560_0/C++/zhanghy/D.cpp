#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T;
int X,R,C;

int main() {
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/D1.in","r",stdin);
    freopen("/Users/zhanghanyuan/Documents/codejam/Qualification/D1.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d%d%d",&X,&R,&C);
        if (R*C % X == 0) {
            if (X == 1 || X == 2) printf("Case #%d: GABRIEL\n",kase);
            else if (X == 3){
                if (R*C == 3) printf("Case #%d: RICHARD\n",kase);
                else printf("Case #%d: GABRIEL\n",kase);
            } else if (X == 4) {
                if (R*C >= 12) printf("Case #%d: GABRIEL\n",kase);
                else printf("Case #%d: RICHARD\n",kase);
            }
        } else printf("Case #%d: RICHARD\n",kase);
    }
    return 0;
}

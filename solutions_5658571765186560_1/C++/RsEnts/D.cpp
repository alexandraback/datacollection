#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int T, X, R, C;

int main() {
    int i, j, T0 = 0;
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    scanf("%d", &T);
    //cerr << "\"" << endl;
    for( ; T; --T) {
        scanf("%d%d%d", &X, &R, &C);
        if(X >= 7 || R * C % X != 0) {
            printf("Case #%d: RICHARD\n", ++T0);
            continue;
        }
        if(X == 1) {
            printf("Case #%d: GABRIEL\n", ++T0);
            continue;
        }
        if(X == 2) {
            printf("Case #%d: GABRIEL\n", ++T0);
            continue;
        }
        if(X == 3) {
            if(min(R, C) == 1) {
                printf("Case #%d: RICHARD\n", ++T0);
                continue;
            }
            printf("Case #%d: GABRIEL\n", ++T0);
            continue;
        }
        if(X == 4) {
            if(min(R, C) <= 2) {
                printf("Case #%d: RICHARD\n", ++T0);
                continue;
            }
            printf("Case #%d: GABRIEL\n", ++T0);
            continue;
        }
        if(X == 5) {
            if(min(R, C) <= 3) {
                printf("Case #%d: RICHARD\n", ++T0);
                continue;
            }
            printf("Case #%d: GABRIEL\n", ++T0);
        }
        if(X == 6) {
            if(min(R, C) <= 3) {
                printf("Case #%d: RICHARD\n", ++T0);
                continue;
            }
            printf("Case #%d: GABRIEL\n", ++T0);
        }
    }
    return 0;
}

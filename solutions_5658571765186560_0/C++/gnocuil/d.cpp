#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    cin >> T;
    bool d[30][30] = {0};
    d[2][3] = d[3][2] = 1;
    for (int i = 1; i <= 20; ++i)
        for (int j = 1; j <= 20; ++j) {
            for (int k = 1; k < i; ++k)
                d[i][j] |= d[i-k][j] && d[k][j];
            for (int k = 1; k < j; ++k)
                d[i][j] |= d[i][j-k] && d[i][k];
        }
    bool h[30][30] = {0};
    h[2][4] = d[4][2] = 1;
    for (int i = 1; i <= 20; ++i)
        for (int j = 1; j <= 20; ++j) {
            for (int k = 1; k < i; ++k)
                h[i][j] |= h[i-k][j] && h[k][j];
            for (int k = 1; k < j; ++k)
                h[i][j] |= h[i][j-k] && h[i][k];
        }
    
    for (int t = 1; t <= T; ++t) {
        int x, r, c;
        cin >> x >> r >> c;
        if (r * c % x != 0) {
            printf("Case #%d: RICHARD\n", t);
            continue;
        }
        
        if (x == 1) {
            printf("Case #%d: GABRIEL\n", t);
            continue;
        }
        if (x > 4) {
            printf("Case #%d: RICHARD\n", t);
            continue;
        }
        //2
        if (x == 2) {
            if (r % 2 == 0 || c % 2 == 0) {
                printf("Case #%d: GABRIEL\n", t);
            } else {
                printf("Case #%d: RICHARD\n", t);
            }
            continue;
        }
        //4
        if (x == 4) {
            if (!h[r][c]) {
                printf("Case #%d: RICHARD\n", t);
                continue;
            }
            if (r % 4 != 0 || c % 4 != 0) {
                printf("Case #%d: RICHARD\n", t);
                continue;
            }
            printf("Case #%d: GABRIEL\n", t);
            continue;
        }
        
        //3
        if (d[r][c]) {
            printf("Case #%d: GABRIEL\n", t);
        } else {
            printf("Case #%d: RICHARD\n", t);
        }
    }
}

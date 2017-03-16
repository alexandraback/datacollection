#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int T, X, Y;
char dir[4][10] = {"WE", "EW", "SN", "NS"};
char ret[500];
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        memset(ret, '\0', sizeof(ret));
        scanf("%d%d", &X, &Y);
        if (X > 0) {
            for (int i = 0; i < X; i++) {
                strcat(ret, dir[0]);
            }
        } else if (X < 0) {
            for (int i = 0; i < -X; i++) {
                strcat(ret, dir[1]);
            }
        }

        if (Y > 0) {
            for (int i = 0; i < Y; i++) {
                strcat(ret, dir[2]);
            }
        } else if (Y < 0) {
            for (int i = 0; i < -Y; i++) {
                strcat(ret, dir[3]);
            }
        }
        printf("Case #%d: %s\n", cas, ret);

    }
    return 0;
}

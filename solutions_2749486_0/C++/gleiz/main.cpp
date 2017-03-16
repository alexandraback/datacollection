#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

char* dir[6] = {"WE", // x + 1
    "EW", //x-1
    "NS", //y - 1
    "SN", // y + 1
};

int main()
{
    int T = 0;
    int x = 0, y = 0;

    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++){
        scanf("%d %d", &x, &y);
        printf("Case #%d: ", cas);

        int d = -1, acc = 0;
        if (x < 0){
            d = 1;
            acc = abs(x);
        }else if (x > 0){
            d = 0;
            acc = x;
        }

        for (int i = 0; i<acc; i++){
            printf("%s", dir[d]);
        }

        acc = 0;
        if (y < 0){
            d = 2;
            acc = abs(y);
        }else if (y > 0){
            d = 3;
            acc = y;
        }

        for (int i = 0; i<acc; i++){
            printf("%s", dir[d]);
        }
        printf("\n");
    }
    return 0;
}

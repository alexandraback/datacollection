#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX = 1000008;
typedef long long LL;
int sx, sy;
LL ans;
char ret[MAX];


void work(int x, int y)
{
    int i = 0;
    if (x < 0) {
        x = -x;
        while (x--) {
            ret[i++] = 'E';
            ret[i++] = 'W';
        }
    }
    else {
        while (x--) {
            ret[i++] = 'W';
            ret[i++] = 'E';
        }
    }
    
    if (y < 0) {
        y = -y;
        while (y--) {
            ret[i++] = 'N';
            ret[i++] = 'S';
        }
    }
    else {
        while (y--) {
            ret[i++] = 'S';
            ret[i++] = 'N';
        }
    }
    
    ret[i] = '\0';
}


int main()
{
    freopen("5b0.in", "r", stdin);
    freopen("5b0.out", "w", stdout);

    int cas;
    scanf("%d", &cas);
    for (int icase = 1; icase <= cas; ++icase) {
        scanf("%d%d", &sx, &sy);
        work(sx, sy);
       printf("Case #%d: %s\n", icase, ret);
    }

}

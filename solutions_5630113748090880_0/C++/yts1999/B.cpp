#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool v[2510];

int main() {
    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:",t);
        memset(v,0,sizeof(v));
        int n;
        scanf("%d",&n);
        for (int i = 1; i < 2 * n; i++)
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d",&x);
                v[x] = ! v[x];
            }
        for (int i = 1; i <= 2500; i++)
            if (v[i])
                printf(" %d",i);
        printf("\n");
    }
    return 0;
}

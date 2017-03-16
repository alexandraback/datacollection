#include <stdio.h>
#include "stdlib.h"

int h[3000];

int main() {
    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("B-small-attempt0.out.txt", "w", stdout);
    int t,tt;
    scanf("%d",&tt);
    for (t=1;t<=tt;t++){
        int n;
        scanf("%d",&n);
        for (int i=0;i<2510;i++)
            h[i]=0;
        for (int i=0;i<(2*n-1)*n;i++){
            int j;
            scanf("%d",&j);
            h[j]++;
        }
        printf("Case #%d:",t);
        for (int i=0;i<2510;i++)
            if (h[i]%2==1)
                printf(" %d",i);
        printf("\n");
    }
    return 0;
}

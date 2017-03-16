#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int T, x, y, i;
    scanf("%d", &T);
    for(i=1;i<=T;i++) {

        scanf("%d", &x);
        scanf("%d", &y);

        printf("Case #%d: ", i);
        
        if (x > 0)
        {
            while(x--)
            {
                printf("WE");
            }
        }
        else
        {
            while(x++)
            {
                printf("EW");
            }
        }

        if (y > 0)
        {
            while(y--)
            {
                printf("SN");
            }
        }
        else
        {
            while(y++)
            {
                printf("NS");
            }
        }
        printf("\n");
    }
    return 1;
}


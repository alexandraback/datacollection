#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
// Round 1C-A
int main()
{
    int T,i;
    scanf("%d",&T);
    for (i=1;i<=T;i++) {
        int resA;
        int R,C,W;
        resA=0;
        scanf("%d%d%d",&R,&C,&W);
        int coup=0;
        int compt=W;
        while(compt<=C) {
            resA++;
            compt+=W;
        }
        coup=resA;
        resA=resA*R;
        resA+=W;
        if (C==(compt-W)) {
            resA-=1;
        }


        printf("Case #%d: %d\n",i,resA);
    }
    return 0;
}

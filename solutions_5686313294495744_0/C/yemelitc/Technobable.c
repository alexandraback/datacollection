#include <stdio.h>
#include <string.h>

int main()
{
    int x, T;
    int i, j, y, N, k;
    char F[1000][20+1];
    char S[1000][20+1];
    int FS, FC[1000][2];
    int SS, SC[1000][2];

    scanf("%d", &T);

    for(x=1; x<=T; x++)
    {
        FS=0;
        SS=0;
        scanf("%d", &N);
        for(i=0; i<N; i++)
        {
            scanf("%s %s", F[i], S[i]);

            for(j=0; j<FS; j++)
            {
                if(0==strcmp(F[FC[j][0]], F[i]))
                { FC[j][1]++; break; }
            }
            if(j==FS)
            {
                FC[FS][0] = i;
                FC[FS][1] = 1;
                FS++;
            }

            for(j=0; j<SS; j++)
            {
                if(0==strcmp(S[SC[j][0]], S[i]))
                { SC[j][1]++; break; }
            }
            if(j==SS)
            {
                SC[SS][0] = i;
                SC[SS][1] = 1;
                SS++;
            }
        }
        /*printf("FS=%d SS=%d\n", FS, SS);
        for(i=0; i<FS; i++)
            printf("%d %s\n", FC[i][1], F[FC[i][0]]);
        printf("-----------------\n");
        for(i=0; i<SS; i++)
            printf("%d %s\n", SC[i][1], S[SC[i][0]]);
        printf("---------------------------\n");*/

        y=0;
        for(i=0; i<N; i++)
        {
            for(j=0; j<FS; j++)
            {
                if(0==strcmp(F[FC[j][0]], F[i]))
                    break;
            }
            if(j==FS) printf("j==FS\n");

            for(k=0; k<SS; k++)
            {
                if(0==strcmp(S[SC[k][0]], S[i]))
                    break;
            }
            if(k==SS) printf("k==SS\n");

            if(FC[j][1]!=1 && SC[k][1]!=1)
            {
                FC[j][1]--;
                SC[k][1]--;
                y++;
            }
        }

        printf("Case #%d: %d\n", x, y);
    }
}


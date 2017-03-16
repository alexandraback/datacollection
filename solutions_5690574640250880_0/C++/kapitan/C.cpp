#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#define FOR(x,z) for(int x=0;x<(z);++x)
#define DS(i) fprintf(stderr, "DEBUG: %s\n",i);
#define DI(i) fprintf(stderr, "DEBUG: %d\n",i);
#define DF(i) fprintf(stderr, "DEBUG: %f\n",i);
using namespace std;
int R, C, M;

void wczytaj()
{
    scanf("%d %d %d", &R, &C, &M);
}
void wykonaj()
{
    //printf("%d %d %d\n", R, C, M);
    int X = R*C-M;
    if(X<4)
    {
        if(R>1&&C>1)
            {
                printf("%s\n", "Impossible");
                return;
            }
        else if(X<2)
            {
                printf("%s\n", "Impossible");
                return;
            }
    }
    else if(X==5||X==7)
        {
            printf("%s\n", "Impossible");
            return;
        }

    if(C==1)
    {
        printf("\nc\n");
        FOR(i,(X-1))
            printf(".\n");
        FOR(j,(R-X))
            printf("*\n");
    }
    else if(R==1)
    {
        printf("\nc");
        FOR(i,(X-1))
            printf(".");
        FOR(j,(C-X))
            printf("*");
        printf("\n");
    }
    else if(X%2==0)
    {
        printf("\n");
        int X2=X/2;
        //printf("%d %d\n", X, X2);
        if(C>X2)
        {
            printf("c");
            X--;
            FOR(i,C-1)
            {
                if(X>X2)
                {
                    printf(".");
                    X--;
                }
                else
                    printf("*");
            }
            printf("\n");
            FOR(i,C)
            {
                if(0<X)
                {
                    printf(".");
                    X--;
                }
                else
                    printf("*");
            }
            printf("\n");
            FOR(i,(R-2))
                {
                FOR(j,C)
                    printf("*");
                printf("\n");
                }
        }

    }
    else
        {

            printf("\nc");
            FOR(i,(C-1))
                printf(".");
            printf("\n");
            X-=C;
            FOR(i,(R-1))
            {
                FOR(j,C)
                {
                    if(0<X)
                    {
                        printf(".");
                        X--;
                    }
                    else
                        printf("*");
                }
                printf("\n");
            }
        }

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        wczytaj();
        DI(t)
        printf("Case #%d: ",t);
        wykonaj();
    }
    return 0;
}

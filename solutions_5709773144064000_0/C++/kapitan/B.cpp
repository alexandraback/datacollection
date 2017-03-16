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
double C, F, X;

void wczytaj()
{
    scanf("%lf %lf %lf", &C, &F, &X);
    //printf("%.7lf %.7lf %.7lf\n", C, F, X);
}
void wykonaj()
{
    double f =2;
    double w = X/f;
    double o=0;
    while(1)
    {
        if(w<o+C/f+X/(f+F))
            break;
        else
        {
            w=o+C/f+X/(f+F);
            o+=C/f;
            f+=F;
        }

    }
    printf("%.7lf\n", w);
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

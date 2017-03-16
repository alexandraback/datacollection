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
int N;
vector<double> v1,v2;
void wczytaj()
{
    scanf("%d", &N);
    double d;
    FOR(i,N)
        {
            scanf("%lf", &d);
            v1.push_back(d);
        }
    FOR(i,N)
        {
            scanf("%lf", &d);
            v2.push_back(d);
        }
    sort (v1.begin(), v1.end());
    sort (v2.begin(), v2.end());
}
void wykonaj()
{
    int dw=0, w=N;
    int j=0;
    FOR(i,N)
    {
        while(j<N)
        {
            if(v1[i]<v2[j])
            {
                w--;
                j++;
                break;
            }
            else
                j++;
        }
    }
    j=0;
    FOR(i,N)
    {
        while(j<N)
        {
            if(v1[j]>v2[i])
            {
                dw++;
                j++;
                break;
            }
            else
                j++;
        }
    }


    printf("%d %d\n", dw, w);
    v1.clear();
    v2.clear();
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

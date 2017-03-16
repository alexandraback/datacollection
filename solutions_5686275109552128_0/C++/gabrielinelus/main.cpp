#include <cstdio>
#include <cmath>


#define INF 0x3f3f3f3f

using namespace std;

int fixat,N,v[2000];
int cost,best,maxval;


int main()
{
    freopen("pancake.in","r",stdin);
    freopen("pancake.out","w",stdout);

    int T;
    scanf("%d",&T);
    for(int tst = 1; tst <= T; ++tst)
    {
        scanf("%d",&N);
        best = INF;
        maxval = -INF;
        for(int i =1; i <= N; ++i)
        {
            scanf("%d",&v[i]);
            if(maxval < v[i])
                maxval = v[i];
        }
        int crt;
        for(fixat = 1; fixat <= maxval; ++fixat)
        {
            crt = fixat;
            for(int i = 1; i <= N; ++i)
            {
                int dif = v[i] - fixat;
                if(dif <= 0)
                    continue;
                crt += ceil((double)(dif/(1.0*fixat)));
            }
            if(best > crt)
                best = crt;
        }
        printf("Case #%d: %d\n",tst,best);
    }


    return 0;
}

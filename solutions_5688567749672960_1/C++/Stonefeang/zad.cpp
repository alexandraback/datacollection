#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int t;
long long n;
int tab[1000007];

long long rew(long long v)
{
    long long ret=0;
    while(v)
    {
        ret*=10;
        ret+=v%10;
        v/=10;
    }
    return ret;
}

int ilec(long long v)
{
    int ret=0;
    while(v)
    {
        ret++;
        v/=10;
    }
    return ret;
}

queue <int> kol;
int u;

long long wyn;
long long v;

long long wyn1, wyn2;
long long pier, pier2;

int main()
{
    for (int i=1; i<=1000000; i++)
    {
        tab[i]=i+1;
    }
    kol.push(0);
    while(!kol.empty())
    {
        u=kol.front();
        kol.pop();
        if (tab[u+1]>tab[u]+1)
        {
            tab[u+1]=tab[u]+1;
            kol.push(u+1);
        }
        if (tab[rew(u)]>tab[u]+1)
        {
            tab[rew(u)]=tab[u]+1;
            kol.push(rew(u));
        }
    }
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        scanf("%lld", &n);
        if (n<=10000)
        {
            printf("Case #%d: %d\n", i, tab[n]);
            continue;
        }
        v=10000;
        wyn=tab[10000];
        while(1)
        {
            if (ilec(v)<ilec(n))
            {
                if (ilec(v)&1)
                {
                    pier=sqrt(v);
                    pier2=sqrt(v*100);
                }
                else
                {
                    pier=sqrt(v*10);
                    pier2=pier;
                }
                wyn+=pier+pier2-1;
                //printf("%lld %lld       %lld %d\n", pier, pier2, v, ilec(v));
                v*=10;


                continue;
            }
            wyn1=wyn+n-v;

            if (ilec(v)&1)
            {
                pier=sqrt(v);
                pier2=sqrt(v*100);
            }
            else
            {
                pier=sqrt(v*10);
                pier2=pier;
            }
            //printf("%lld %lld       %lld %d\n", pier, pier2, v, ilec(v));

            //printf("%lld %lld\n", (n%pier), (rew(n)%pier2));

            wyn2=wyn+(n%pier)+(rew(n)%pier2);

            v=n;
            break;
        }
        printf("Case #%d: %lld\n", i, min(wyn1, wyn2));
    }
    return 0;
}


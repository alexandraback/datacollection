#include <cstdio>
#include <queue>
using namespace std;

int t;
int n;
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

queue <int> kol;
int u;

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
        scanf("%d", &n);
        printf("Case #%d: %d\n", i, tab[n]);
    }
    return 0;
}

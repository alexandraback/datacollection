#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <ctime>

#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define S(n)	    scanf("%d",&n)
#define P(n)	    printf("%d\n",n)
#define Sl(n)	    scanf("%lld",&n)
#define Pl(n)	    printf("%lld\n",n)
#define Sf(n)       scanf("%lf",&n)
#define Ss(n)       scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;

int pr[10],v[10],n,m,K,l;

void mark(int p)
{
    int i;
    for(i=1;i<=K;i++)
    {
        if(pr[i]==p)
            v[i]=1;
    }
}

void func()
{
    int i,j,k,p,q,f;
    l++;
    for(i=2;i<=m;i++)
    {
        for(j=2;j<=m;j++)
        {
            for(k=2;k<=m;k++)
            {
                CLR(v);
                p=1;
                mark(p);
                p=i;
                mark(p);
                p=j;
                mark(p);
                p=k;
                mark(p);
                p=i*j;
                mark(p);
                p=j*k;
                mark(p);
                p=i*k;
                mark(p);
                p=i*j*k;
                mark(p);

                f=1;
                for(q=1;q<=K;q++)
                {
                    if(v[q]==0)
                        f=0;
                }
                if(f==1)
                {
                    printf("%d%d%d\n",i,j,k);
                    return;
                }
            }
        }
    }

    printf("%d%d%d\n",2,2,2);
        return;
}

int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,k,r;
    S(t);
    while(t--)
    {
        S(r);  S(n);  S(m);  S(K);
        printf("Case #%d:\n",1);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=K;j++)
            {
                S(pr[j]);
            }
            func();
        }
    }
    return 0;
}


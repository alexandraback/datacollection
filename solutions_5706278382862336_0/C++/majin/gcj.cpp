
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<sstream>
#include<fstream>
using namespace std;
#define INF 2000000000
#define INFLL (1LL<<62)
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i,m,n) for(int i=(m);i<(n);i++)
//#define ull unsigned long long
//#define lint long long
#define MX 10000001
long long gcd(long long a,long long b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,k,l,n,m,t;
    scanf("%d",&t);
    int ct=0;
    long long p,q,r;
    while(t--)
    {
        ct++;
        double ans=0;
        scanf("%lld/%lld",&p,&q);
        r=gcd(p,q);
        p/=r;
        q/=r;
        double c;
        c=double(q)/double(p);
        ans=log2(c);
        int ret = ceil(ans);
        double qcheck=log2(double(q));

        if((ret>40)||(qcheck!=(int)qcheck))
        {
            printf("Case #%d: impossible\n",ct);
        }
        else
        {
            printf("Case #%d: %d\n", ct, ret);
        }
    }
    return 0;
}

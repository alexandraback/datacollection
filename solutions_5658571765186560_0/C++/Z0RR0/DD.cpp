#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define SP printf(" ")
#define loj(x) printf("Case %d:",x)
#define Loj(x) printf("Case %lld:",x)
#define debug(str,x) cout << str << " " << x << endl;
#define Max 1000000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("doutsmall.txt","w",stdout);
    LL t,T,r,c,x;
    sl(T);
    rep(t,T)
    {
        slll(x,r,c);
        if(c > r)swap(c,r);
        LL a = (x+2)/2;
        LL b = (x+1)/2;
        printf("Case #%lld: ",t);
        if( (r*c)%x )
        {
             ///not
             puts("RICHARD");
        }
        else
        {
            if(r >= a && c>=b)
            {
                if(x-2 < c)
                {
                    ///oka
                    puts("GABRIEL");
                }
                else
                {
                    ///not
                    puts("RICHARD");
                }
            }
            else
            {
                ///not
                puts("RICHARD");
            }
        }

    }
    return Afridi;
}

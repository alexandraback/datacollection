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
#define Max 10005
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

char str[Max];
LL ara[Max*100 + 10],ind,mat[Max*100 + 10];
LL n,x;

LL get(char c)
{
    if(c == 'i')return 2;
    else if(c == 'j')return 3;
    else return 4;
}

LL table[10][10];
void prework()
{
    table[1][1] = 1;
    table[1][2] = 2;
    table[1][3] = 3;
    table[1][4] = 4;
    table[2][1] = 2;
    table[2][2] = -1;
    table[2][3] = 4;
    table[2][4] = -3;
    table[3][1] = 3;
    table[3][2] = -4;
    table[3][3] = -1;
    table[3][4] = 2;
    table[4][1] = 4;
    table[4][2] = 3;
    table[4][3] = -2;
    table[4][4] = -1;
}

LL mul(LL a,LL b)
{
    LL f = a*b;
    if(f < 0)f = -1;
    else f = 1;
    a = abs(a);
    b = abs(b);
    LL ans = table[a][b];
    ans*=f;
    return ans;
}

LL fun()
{
    LL prev = 1,match = 0,key,i,oka = 0;
    for(i=1;i<=ind;i++)
    {
        mat[i] = mul(prev,ara[i]);
        prev = mat[i];
        if(match == 0 && mat[i] == 2)
        {
            match = 1;
        }
        else if(match == 1 && mat[i] == 4)
        {
            match = 2;
        }
        if(i == n)
        {
            key = mat[i];
        }
    }
    if(key == -1)
    {
        if(x & 1)oka = 1;
    }
    else
    {
        if(x%4 == 2)oka = 1;
    }
    //printf("key %lld\n",key);
    if(oka)
    {
        if(match == 2)return 1;
        else return 0;
    }
    else return 0;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("coutsmall.txt","w",stdout);
    LL t,T,i,j;
    prework();
    sl(T);
    rep(t,T)
    {
        sll(n,x);
        ss(str);
        if(x < 100)
        {
            ind = 0;
            for(i=1;i<=x;i++)
            {
                for(j=0;j<n;j++)
                {
                    ara[++ind] = get(str[j]);
                }
            }
        }
        else
        {
            ind = 0;
            for(i=1;i<=100;i++)
            {
                for(j=0;j<n;j++)
                {
                    ara[++ind] = get(str[j]);
                }
            }
        }
        LL ans = fun();
        if(ans)printf("Case #%lld: YES\n",t);
        else printf("Case #%lld: NO\n",t);
    }
    return Afridi;
}

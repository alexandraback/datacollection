#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9
#define Afridi 0

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
#define NL printf("\n")
#define SP printf(" ")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 1000000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

char str[Max],key[Max],tex[Max];
LL z[Max],n;
LL k,l,s,check[100];

void zalgo()
{
    LL i,l,r;
    l = r = 0;
    for(i=1; i<n; i++)
    {
        if(i > r)
        {
            l = r = i;
            while(r < n && str[r] == str[r-l])r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            LL k = i - l;
            if(z[k] < r-i+1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while(r < n && str[r] == str[r-l])r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}
LL go()
{
    LL i;
    for(i=0;i<n;i++)
    {
        if(z[i] + i == n)
        {
            return (s - z[i])/i;
        }
    }
    return s/n;
}


LL match(char a[10])
{
    //printf("jjibone\n");
    LL i,j,cnt = 0;
    char tmp[10];
    for(i=0;i<s;i++)
    {
        for(j=0;j<l;j++)
        {
            tmp[j] = a[i+j];
        }
        tmp[l] = 0;
        if(strcmp(tmp,str) == 0)cnt++;
    }
    return cnt;
}
double fun(LL pos,char a[10])
{
    //printf("a %s\n",a);
    if(pos == s)
    {
        a[pos] = 0;
        //printf("a %s\n",a);
        return (double)match(a);
    }
    //printf("ho\n");
    double ans = 0.0;
    //printf("k %lld\n",k);
    char tmp[10];
    strcpy(tmp,a);
    for(LL i=0;i<k;i++)
    {
        //printf("i %lld\n",i);
        tmp[pos] = key[i];
        ans += fun(pos+1,tmp);
    }
    //printf("hi\n");
    return (double)ans/k;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("bsmall.txt","w",stdout);
    LL t,T,i;
    sl(T);
    rep(t,T)
    {
        slll(k,l,s);
        ss(key);
        LL len = strlen(key);
        mem(check,0);
        Rep(i,len)check[ key[i] - 'A' ]++;
        ss(str);
        n = strlen(str);
        zalgo();
        LL banana = go();
        Rep(i,n)if(check[ str[i] - 'A' ] == 0)banana = 0;
        printf("Case #%lld: %.8lf\n",t,(double)banana - fun(0,""));
    }
    return Afridi;
}

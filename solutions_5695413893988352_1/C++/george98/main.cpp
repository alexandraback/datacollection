#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
char v1[20],v2[20],sol1[20],sol2[20];
int q1[1010],q2[1010],nr1,nr2,n;

pair<ll,ll> solve(ll s1,ll s2,int poz)
{
    for(int i=poz;i<=n;i++)
    {
        s1*=10;s2*=10;
        if(v1[i]=='?') s1+=9*(s1<s2);
        else s1+=v1[i]-'0';
        if(v2[i]=='?') s2+=9*(s1>s2);
        else s2+=v2[i]-'0';
    }
    return {s1,s2};
}

void update(pair<ll,ll> &sol,pair<ll,ll> s)
{
    if(sol.first==-1) sol=s;
    else if(abs(s.first-s.second)<abs(sol.first-sol.second)) sol=s;
    else if(abs(s.first-s.second)==abs(sol.first-sol.second) && s<sol) sol=s;
}

int nrcifre(ll a)
{
    int s=0;
    for(;a;s++,a/=10);
    return s;
}

void back1(int poz,int s)
{
    if(poz==n+1) q1[++nr1]=s;
    else
    {
        if(v1[poz]!='?') back1(poz+1,s*10+v1[poz]-'0');
        else for(int i=0;i<=9;i++) back1(poz+1,s*10+i);
    }
}

void back2(int poz,int s)
{
    if(poz==n+1) q2[++nr2]=s;
    else
    {
        if(v2[poz]!='?') back2(poz+1,s*10+v2[poz]-'0');
        else for(int i=0;i<=9;i++) back2(poz+1,s*10+i);
    }
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        scanf("\n%s %s",v1+1,v2+1);
        n=strlen(v1+1);
        ll s1=0,s2=0;
        int ok=1;
        pair<ll,ll> sol={-1,-1};
        for(int i=1;i<=n;i++)
            if(v1[i]!='?' && v2[i]!='?')
            {
                s1=s1*10+v1[i]-'0';
                s2=s2*10+v2[i]-'0';
                if(s1!=s2)
                {
                    update(sol,solve(s1,s2,i+1));
                    ok=0;
                    break;
                }
            }
            else if(v1[i]!='?')
            {
                ll a1=s1*10+v1[i]-'0';
                ll a2=s2*10+(v1[i]-'0'+9)%10;
                update(sol,solve(a1,a2,i+1));
                a1=s1*10+v1[i]-'0';
                a2=s2*10+(v1[i]-'0'+1)%10;
                update(sol,solve(a1,a2,i+1));
                s1=s1*10+v1[i]-'0';
                s2=s2*10+v1[i]-'0';
            }
            else if(v2[i]!='?')
            {
                ll a1=s1*10+(v2[i]-'0'+9)%10;
                ll a2=s2*10+v2[i]-'0';
                update(sol,solve(a1,a2,i+1));
                a1=s1*10+(v2[i]-'0'+1)%10;
                a2=s2*10+v2[i]-'0';
                update(sol,solve(a1,a2,i+1));
                s1=s1*10+v2[i]-'0';
                s2=s2*10+v2[i]-'0';
            }
            else
            {
                ll a1=s1*10;
                ll a2=s2*10+1;
                update(sol,solve(a1,a2,i+1));
                a1=s1*10+1;
                a2=s2*10;
                update(sol,solve(a1,a2,i+1));
                s1*=10;
                s2*=10;
            }
        if(ok) update(sol,{s1,s2});
        printf("Case #%d: ",t);
        int s=nrcifre(sol.first);
        for(int i=s+1;i<=n;i++) printf("0");
        if(sol.first!=0) printf("%lld ",sol.first);
        else printf(" ");
        s=nrcifre(sol.second);
        for(int i=s+1;i<=n;i++) printf("0");
        if(sol.second!=0) printf("%lld\n",sol.second);
        else printf("\n");
        /*nr1=0;nr2=0;
        back1(1,0);
        back2(1,0);
        pair<ll,ll> sol1={-1,-1};
        for(int i=1;i<=nr1;i++)
            for(int j=1;j<=nr2;j++) update(sol1,{q1[i],q2[j]});
        if(sol!=sol1)
        {
            int a;
            a++;
        }*/
    }
    return 0;
}

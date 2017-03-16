//+++++++++++++++++++++++++++++//
////      Karan Aggarwal         //
////       IIIT-Hyderabad        //
////+++++++++++++++++++++++++++++//
//// Topic: 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<cassert>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

struct tribe
{
    int day;
    int dday;
    int l,r,s,ds,dp,n;
}tr[10];
int power[1000000]={};
int powerless[1000000]={};
int main()
{
    int T,n,m,i,t,j,k,x,N;
    si(T);
    for(t=1;t<=T;t++)
    {
        si(N);
        memset(power,0,sizeof(power));
        memset(powerless,0,sizeof(power));
        int X=0;
        rep(i,N)
        {
            cin>>tr[i].day>>tr[i].n>>tr[i].l>>tr[i].r>>tr[i].s>>tr[i].dday>>tr[i].dp>>tr[i].ds;
            X+=tr[i].n;
        }
        int ans=0;
        while(X)
        {
            int  minday = 1000000000;
            rep(i,N)
                if(tr[i].n)
                    minday=min(minday,tr[i].day);
            
            rep(i,N)
                if(tr[i].n && tr[i].day==minday)
                    for(k=tr[i].l;k<=tr[i].r;k++)
                        if(power[k+500000]<tr[i].s || (k!=tr[i].l && powerless[k+500000]<tr[i].s))
                        {ans++;
                          //  piw(i);
                            break;}
                        
                    
            
            rep(i,N)
                if(tr[i].n && tr[i].day==minday)
                {
                    for(k=tr[i].l;k<=tr[i].r;k++)
                    {
                        power[k+500000] = max(power[k+500000],tr[i].s);
                        if(k!=tr[i].l)
                            powerless[k+500000]=max(powerless[k+500000],tr[i].s);
                    }
                    tr[i].l+=tr[i].dp;
                    tr[i].r+=tr[i].dp;
                    tr[i].s+=tr[i].ds;
                    tr[i].day+=tr[i].dday;
                    tr[i].n--;
                    X--;
                }
        }
  //      pn;
        printf("Case #%d: ",t);
        pin(ans);
    
    }
    return 0;
}


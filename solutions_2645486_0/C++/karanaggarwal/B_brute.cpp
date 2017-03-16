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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) for(int i=0;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define mod 1000000007
#define pi(n) printf("%d",n)
#define pll(n) printf("%lld",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
int MX,TE,G,n,V[100];
int big(int a, int b)
{
    return a>b?a:b;
}
int small(int a, int b)
{
    return a<b?a:b;
}
void f(int ind, int ans,int E)
{
    int spend,i;
    if(ind==n)
    {
        MX = big(MX,ans);
        return ;
    }
    for(spend=0;spend<=E;spend++)
        f(ind+1,ans+(spend*V[ind]),small(TE,E-spend+G));
}
int main()
{
    int m,i,t,j,k,x;
    si(t);int T=t;
    while(t--)
    {
        si(TE);
        si(G);
        si(n);
        rep(i,n)
            si(V[i]);
        MX =0;
        f(0,0,TE);
        cout<<"Case #"<<T-t<<": "<<MX<<endl;
    }
    return 0;
}


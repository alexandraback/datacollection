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

int main()
{
    int y,T,n,m,i,t,j,k,x;
    si(T);
    for(t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        si(x);si(y);
        if(x>=0)
            rep(i,x) cout<<"WE";
        else rep(i,abs(x)) cout<<"EW";
        if(y>=0)
            rep(i,y) cout<<"SN";
        else
            rep(i,abs(y)) cout<<"NS";
        pn;
    }
    return 0;
}


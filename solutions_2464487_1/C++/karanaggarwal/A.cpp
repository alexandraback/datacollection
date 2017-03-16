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
#define pll(n) printf("%llud",n)
#define sll(n) scanf("%llud",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
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
    unsigned long long t,r,a,ans,x,aa,bb,p,start,end,mid;
    sll(t);
    LL T=t;
    while(t--)
    {
        sll(r);
        sll(p);
        a = (r<<1)  +1;
        x = p/a;
        end = x+1;
        start=0;
        x = (start+end)>>1;
        aa = (2*(x*(x-1))) + (x*a);
        bb = (2*(x+1)*(x)) + (x+1)*a;
    //    cout <<a<<" "<<x<<" "<< aa <<" "<<bb<<endl;
        while( bb<p || aa>p)
        {
            if(bb<p)
                start=x+1;
            else end = x-1;
            x = (start+end)>>1;
        aa = (2*(x*(x-1))) + (x*a);
        bb = (2*(x+1)*(x)) + (x+1)*a;
 //       cout <<a<<" "<<x<<" "<< aa <<" "<<bb<<endl;
        }
        if(bb==p)
            ans = x+1;
        else
        ans = x;
        cout<<"Case #"<<T-t<<": "<<ans<<endl;
    }
    return 0;
}


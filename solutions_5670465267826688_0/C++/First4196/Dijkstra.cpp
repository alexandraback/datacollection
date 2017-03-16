#include    <stdio.h>
#include    <iostream>
#include    <queue>
#include    <stack>
#include    <list>
#include    <vector>
#include    <map>
#include    <set>
#include    <cmath>
#include    <ctime>
#include    <string.h>
#include    <algorithm>
#define     SF              scanf
#define     S1(a)           SF("%d",&a);
#define     S2(a,b)         SF("%d%d",&a,&b);
#define     S3(a,b,c)       SF("%d%d%d",&a,&b,&c);
#define     S4(a,b,c,d)     SF("%d%d%d%d",&a,&b,&c,&d);
#define     S5(a,b,c,d,e)   SF("%d%d%d%d%d",&a,&b,&c,&d,&e);
#define     SL1(a)          SF("%lld",&a);
#define     SL2(a,b)        SF("%lld%lld",&a,&b);
#define     SL3(a,b,c)      SF("%lld%lld%lld",&a,&b,&c);
#define     SL4(a,b,c,d)    SF("%lld%lld%lld%lld",&a,&b,&c,&d);
#define     SL5(a,b,c,d,e)  SF("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
#define     SFC(a)          SF(" %c",&a);
#define     SFS(a)          SF("%s",a);
#define     PF              printf
#define     P1(a)           PF("%d ",a);
#define     P2(a,b)         PF("%d %d ",a,b);
#define     P3(a,b,c)       PF("%d %d %d ",a,b,c);
#define     P4(a,b,c,d)     PF("%d %d %d %d ",a,b,c,d);
#define     P5(a,b,c,d,e)   PF("%d %d %d %d %d ",a,b,c,d,e);
#define     PL1(a)          PF("%lld ",a);
#define     PL2(a,b)        PF("%lld %lld ",a,b);
#define     PL3(a,b,c)      PF("%lld %lld %lld ",a,b,c);
#define     PL4(a,b,c,d)    PF("%lld %lld %lld %lld ",a,b,c,d);
#define     PL5(a,b,c,d,e)  PF("%lld %lld %lld %lld %lld ",a,b,c,d,e);
#define     PFC(a)          PF("%c",a);
#define     PFS(a)          PF("%s",a);
#define     SP              PF(" ");
#define     EL              PF("\n");
#define     LINE            PF("--------------------\n");
#define     BO              bool operator
#define     FRI(a)          freopen(a,"r",stdin);
#define     FRO(a)          freopen(a,"w",stdout);
#define     F0(a,b)         for(int a=0;a<=b;a++)
#define     R0(a,b)         for(int a=b;a>=0;a--)
#define     F1(a,b)         for(int a=1;a<=b;a++)
#define     R1(a,b)         for(int a=b;a>=1;a--)
#define     FV(a,b)         for(int a=0;a<v[b].size();a++)
#define     RV(a,b)         for(int a=0;a<rv[b].size();a++)
#define     PII             pair<int,int>
#define     MII             map<int,int>
#define     LL              long long
#define     MP              make_pair
#define     IB              push_back
#define     IF              push_front
#define     DB              pop_back()
#define     DF              pop_front()
#define     FI              first
#define     SC              second
#define     QT              Q.top()
#define     QF              Q.front()
#define     QB              Q.back()
#define     ST              S.top()
#define     SZ              size()
#define     PI              3.141592653589793
#define     MOD             1000000007
#define     INF             2000000000
#define     LINF            9000000000000000000
using namespace std;

int tc,t,l,x,v,k,s[111111];
char c;
const int mul[10][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,2,3,4,5,6,7,8,0},
    {0,2,1,4,3,6,5,8,7,0},
    {0,3,4,2,1,7,8,6,5,0},
    {0,4,3,1,2,8,7,5,6,0},
    {0,5,6,8,7,2,1,3,4,0},
    {0,6,5,7,8,1,2,4,3,0},
    {0,7,8,5,6,4,3,2,1,0},
    {0,8,7,6,5,3,4,1,2,0},
    {0,0,0,0,0,0,0,0,0,0}
};
// 1  2  3  4  5  6  7  8
// 1 -1  i -i  j -j  k -k
int main(){
    FRI("C-small-attempt0.in")
    FRO("out.txt")
    S1(t)
    F1(tc,t){
        S2(l,x)
        if(x>11){
            x=(x%4)+8;
        }
        F1(i,l){
            SFC(c)
            switch(c){
                case 'i': v=3; break;
                case 'j': v=5; break;
                case 'k': v=7; break;
            }
            F0(j,x-1){
                s[i+j*l]=v;
            }
        }
        k=0; v=1;
        F1(i,x*l){
            v=mul[v][s[i]];
            if(k==0 and v==3){
                k=1; v=1;
            }
            else if(k==1 and v==5){
                k=2; v=1;
            }
        }
        if(k==2 and v==7){
            PF("Case #%d: YES\n",tc);
        }
        else{
            PF("Case #%d: NO\n",tc);
        }
    }
    return 0;
}

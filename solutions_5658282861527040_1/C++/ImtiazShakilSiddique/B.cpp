#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;


#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 100005

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

int A[60],B[60],K[60];

ll dp[60][3][3][3];
ll rec(int pos,int prvA,int prvB,int prvK)
{
//    deb("rec",pos,prvA,prvB,prvK);
    if(pos<0) return 1LL;
    ll &ret=dp[pos][prvA][prvB][prvK];
    if(ret!=-1) return ret;

    ret=0;
    int mxA= ( ( prvA ) ? A[pos] : 1 );
    int mxB= ( ( prvB ) ? B[pos] : 1 );
    int mxK= ( ( prvK ) ? K[pos] : 1 );

    int nowA,nowB,nowK;
    int found;
    for(int i=0;i<=mxA;i++)
    {
        for(int j=0;j<=mxB;j++)
        {
            found=(i&j);
            if(found>mxK) continue;

            nowA=0;nowB=0;nowK=0;
            if(i==mxA && prvA) nowA=1;
            if(j==mxB && prvB) nowB=1;
            if(found==mxK && prvK) nowK=1;

            ret+=rec(pos-1,nowA,nowB,nowK);
//            deb("rec",pos,prvA,prvB,prvK);
//            deb("ret",ret);
        }
    }
    return ret;
}

ll getAns(ll a,ll b, ll k)
{
    mem(A,0);mem(B,0);mem(K,0);
    if(a<0 || b<0 || k<0 ) return 0;
    --a;--b;--k;
    int indx=0;
    while(a)
    {
        A[indx]=a%2;
        a/=2;
        indx++;
    }
//    for(int i=5;i>=0;i--) printf("%d ",A[i]);puts("");

    indx=0;
    while(b)
    {
        B[indx]=b%2;
        b/=2;
        indx++;
    }
//    for(int i=5;i>=0;i--) printf("%d ",B[i]);puts("");


    indx=0;
    while(k)
    {
        K[indx]=k%2;
        k/=2;
        indx++;
    }
//    for(int i=5;i>=0;i--) printf("%d ",K[i]);puts("");

    mem(dp,-1);
    return rec(55,1,1,1);





}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll a,b,k;
    int cas,loop=0;
    scanf("%d",&cas);
    while(cas--)
    {
        cin>>a>>b>>k;
        printf("Case #%d: %lld\n",++loop, getAns(a,b,k) );
    }
    return 0;
}


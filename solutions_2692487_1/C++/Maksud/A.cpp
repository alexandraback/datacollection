#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cerr<<" -> "<<#a<<"  "<<a<<endl;
#define oo          (1<<30)
#define ERR         1e-5
#define PRE         1e-8
#define popcount(a) (__builtin_popcountll(a))
#define SZ(a)       ((int)a.size())
#define fs           first
#define sc           second
#define pb          push_back
#define ll          long long
#define mp          make_pair
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define Clear(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fii(a,b)    for(i=a;i<b;i++)
#define fij(a,b)    for(j=a;j<b;j++)
#define fik(a,b)    for(k=a;k<b;k++)
#define fil(a,b)    for(l=a;l<b;l++)
#define ri(i,a)     for(i=0;i<a;i++)
#define rii(a)      for(i=0;i<a;i++)
#define rij(a)      for(j=0;j<a;j++)
#define rik(a)      for(k=0;k<a;k++)
#define ril(a)      for(l=0;l<a;l++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
//#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define INC(a,b,c)   (b<=a&&a<=c)


//#define debug(args...)          {dbg,args; cerr<<endl;}
//#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
#define debug(a...)          {cerr<<" #--> ";dbg,a; cerr<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;




//const double pi=2*acos(0.);
const double pi=acos(-1.0);

const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

typedef pair<int,int> pii;

//typedef double type;
//struct P{
//    type x,y,z;
//    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
//    void scan(){cin>>x>>y>>z;}
//    void scan1(){scanf("%lf%lf%lf",&x,&y,&z);}
//};


//bool operator < (const P &a,const P &b){return a>b;}
//bool com(P a,P b){return;}

//struct pq{int n,w;
//    pq(int nn=0,int ww=0):n(nn),w(ww){}
//    bool operator<(const pq &b) const{return w<b.w;}
//};

VI v;


int go(int a)
{
    int n = SZ(v);
    if(a==1)    return SZ(v);
    int m = SZ(v);
    ll cur=a;
    int cnt=0,i;

    rii(n)
    {
        m = min(m,cnt+n-i);

        if(cur>v[i])cur+=v[i];
        else
        {
            while(cur<=v[i])
            {
                cur+=cur-1;
                cnt++;
            }
            cur+=v[i];
        }
        m = min(m,cnt+n-i-1);
    }

    return m;
}


int main()
{
//    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("outL.in","w",stdout);


    //ios_base::sync_with_stdio(false);
    //std::cout << std::setprecision(13)<<b<<std::endl;
    //assert(ks<0);

    int i,j,k,tks=1,ks=1,a,n;


    scanf("%d",&tks);

    while(tks--)
    {
        v.clear();
        scanf("%d%d",&a,&n);
        rii(n)
        {
            scanf("%d",&j);
            v.pb(j);
        }
        sort(all(v));
        j = go(a);

        printf("Case #%d: %d\n",ks++,j);

    }


    return 0;
}











//#include<iostream>
//#include<sstream>
//#include<string>
//#include<cstdlib>
//#include<vector>
//#include<map>
//#include<queue>
//#include<stack>
//#include<cctype>
//#include<set>
//#include<bitset>
//#include<algorithm>
//#include<list>
//#include<utility>
//#include<functional>
//#include <deque>
//#include <numeric>
//#include <iomanip>
//#include <cstdio>
//#include <cstring>
//#include <ctime>
//#include <assert.h>
//
//
//#include<cmath>
//#include<math.h>
//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<ctype.h>
//
//using namespace std;
//
//#define deb(a)      cerr<<" -> "<<#a<<"  "<<a<<endl;
//#define oo          (1<<30)
//#define ERR         1e-5
//#define PRE         1e-8
//#define popcount(a) (__builtin_popcountll(a))
//#define SZ(a)       ((int)a.size())
//#define fs           first
//#define sc           second
//#define pb          push_back
//#define ll          long long
//#define mp          make_pair
//#define SS          stringstream
//#define VS          vector<string>
//#define VI          vector<int>
//#define CON(a,b)  ((a).find(b)!=(a).end())
//#define mem(a,b)    memset(a,b,sizeof(a))
//#define Clear(a,b)    memset(a,b,sizeof(a))
//#define memc(a,b)   memcpy(a,b,sizeof(b))
//#define accu(a,b,c) accumulate((a),(b),(c))
//#define fi(i,a,b)   for(i=a;i<b;i++)
//#define fii(a,b)    for(i=a;i<b;i++)
//#define fij(a,b)    for(j=a;j<b;j++)
//#define fik(a,b)    for(k=a;k<b;k++)
//#define fil(a,b)    for(l=a;l<b;l++)
//#define ri(i,a)     for(i=0;i<a;i++)
//#define rii(a)      for(i=0;i<a;i++)
//#define rij(a)      for(j=0;j<a;j++)
//#define rik(a)      for(k=0;k<a;k++)
//#define ril(a)      for(l=0;l<a;l++)
//#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
//#define EQ(a,b)     (fabs(a-b)<ERR)
//#define all(a)      (a).begin(),(a).end()
//#define rall(a)      (a).rbegin(),(a).rend()
////#define sqr(a)      ((a)*(a))
//#define p2(a)       (1LL<<a)
//#define EX(msk,a)   (msk&p2(a))
//#define INC(a,b,c)   (b<=a&&a<=c)
//
//
////#define debug(args...)          {dbg,args; cerr<<endl;}
////#define debug(args...)          {cout<<" #--> ";dbg,args; cerr<<endl;}
//#define debug(a...)          {cerr<<" #--> ";dbg,a; cerr<<endl;}
//
//struct debugger
//{
//    ///Collected from rudradevbasak
//    template<typename T> debugger& operator , (const T v)
//    {
//        cerr<<v<<" ";
//        return *this;
//    }
//} dbg;
//
//
//
//
////const double pi=2*acos(0.);
//const double pi=acos(-1.0);
//
//const double eps=1e-7;
//
//template<class TT>TT sqr(TT a){return a*a;}
//
//template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
//template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
//template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}
//
//typedef pair<int,int> pii;
//
////typedef double type;
////struct P{
////    type x,y,z;
////    P(type xi=0,type yi=0,type zi=0):x(xi),y(yi),z(zi){};
////    void scan(){cin>>x>>y>>z;}
////    void scan1(){scanf("%lf%lf%lf",&x,&y,&z);}
////};
//
//
////bool operator < (const P &a,const P &b){return a>b;}
////bool com(P a,P b){return;}
//
////struct pq{int n,w;
////    pq(int nn=0,int ww=0):n(nn),w(ww){}
////    bool operator<(const pq &b) const{return w<b.w;}
////};
//
//typedef long double ld;
//
//ld sqarSum(ld n){return (n*(n+1)*(2*n+1))/6;}
//ld normalSum(ld n){return n*(n+1)/2;}
//ld evenSquarSum(ld n){ return ((n>-0.5)?(4*sqarSum(n)):0);}
//
//ld OddSquarSum(ld n){   return ((n>-0.5)?(4*sqarSum(n)+4*normalSum(n)+n+1):0);}
//
//
//
//ld check(ll r,ld n)
//{
//    if(r&1)
//    {
//        return evenSquarSum(n+(r/2))-OddSquarSum(n+(r/2)-1)-evenSquarSum(r/2)+OddSquarSum((n/2)-1)  ;
//    }
//    ld a,b,c,d;
//
//    a = OddSquarSum(n+(r/2)-1);
//    b = evenSquarSum(n+(r/2));
//    c = OddSquarSum((r/2)-1);
//    d = evenSquarSum((r-2)/2);
//    deb(a);
//    deb(b);
//    deb(c);
//    deb(d);
//    return a- b - c +d;
//}
//
//ll go(int ll r,ll t)
//{
//    ll l=0,h=1000000000,m,i=0;
//
//    while(l<h)
//    {
//        m=(l+h+1)/2;
//        debug(i,m,check(r,m));
//        if(check(r,m)<t+eps)    l = m;
//        else h = m-1;
//        i++;
//    }
//    return l;
//}
//
//
//int main()
//{
////    freopen("in.txt","r",stdin);
////    freopen("out.in","w",stdout);
//
//
//    //ios_base::sync_with_stdio(false);
//    //std::cout << std::setprecision(13)<<b<<std::endl;
//    //assert(ks<0);
//
////    deb();
//
//    int i,j,k,tks=1,ks=1;
//    ll r,t,ans;
//
////    scanf("%d",&tks);
//
//    while(true)
//    {
//        scanf("%I64d%I64d",&r,&t);
//        ans  = go(r,t);
//        printf("Case #%d: %I64d\n",ks++,ans);
//    }
//
//
//    return 0;
//}
//
//

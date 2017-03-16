/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB push_back
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 135010
#define md 1000000007
#define maxp 405018



////////define value/////


int main()
{
    R("in.txt");
    W("out.txt");

    int tc,cs=0;
    I(tc);
    while(tc--)
    {
        int n;
        I(n);

        string a[n+2],b[n+2];
        for(int i=0;i<n;i++)cin>>a[i]>>b[i];
        int ar[n+2];
        int ar1[n+2];
        SET(ar);
        SET(ar1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    ar[i]=(ar[i]|(1<<j));
                }
            }
            for(int j=0;j<n;j++)
            {
                if(b[i]==b[j])
                {
                    ar1[i]=(ar1[i]|(1<<j));
                }
            }
        }
        int ans=0;
        for(int i=1;i<(1<<n);i++)
        {
            bool fl=0;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j)))
                {
                 int cnt=0;
                 int cnt1=0;
                   //cout<<i<<" "<<x<<" "<<y<<" "<<ar[j]<<" "<<ar1[j]<<endl;
                   for(int k=0;k<n;k++)
                   {
                       if(!(i&(1<<k)))
                       {
                           if(ar[j]&(1<<k))cnt++;
                           else if(ar1[j]&(1<<k))cnt1++;
                       }
                   }
                    if(cnt<1||cnt1<1)fl=1;

                }
            }
           // cout<<i<<" "<<fl<<endl;
            if(!fl)ans=max(ans,CB(i));
        }
        PC("Case #%d: %d\n",++cs,ans);
    }


    return 0;
}

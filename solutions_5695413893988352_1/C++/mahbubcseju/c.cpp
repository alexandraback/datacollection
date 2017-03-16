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
#define maxp 2000000000000000000ll



////////define value/////
char a[20];
char b[20];
ll check(int i,int l)
{

    for(int j=i; j<=l; j++)
    {
        if(a[j]==b[j])continue;

        if(a[j]=='?'&&b[j]!='?')continue;
        if(a[j]!='0'&&b[j]=='?')continue;
        ll x=(l-i+1);
        ll ans=(a[j]-'0')*PW(10ll,x);
        ans-=(b[j]-'0')*PW(10ll,x);
        return ans;
    }

    return 0;
}
int main()
{
    R("in.txt");
    W("out.txt");

    int tc,cs=0;
    I(tc);
    while(tc--)
    {

        SC("%s",a+1);

        SC("%s",b+1);
        int l=strlen(a+1);
        int l1=strlen(b+1);
        int len=max(l,l1);
        int st=1;
        int en=1;
        if(l<l1)
        {
            char c[20];
            int len=l1-l;
            st+=len;
            c[0]='0';
            int sz=0;
            for(int i=1; i<=len; i++)c[++sz]='0';
            for(int i=1; i<=l; i++)c[++sz]=a[i];
            c[++sz]='\0';
            strcpy(a+1,c+1);
        }
        else if(l>l1)
        {
            char c[20];
            int len=l-l1;
            en+=len;
            c[0]='0';
            int sz=0;
            for(int i=1; i<=len; i++)c[++sz]='0';
            for(int i=1; i<=l1; i++)c[++sz]=b[i];
            c[++sz]='\0';
            strcpy(b+1,c+1);
        }

        ll  ans=0;
        for(ll i=1; i<=len; i++)
        {
             ll kop=PW(10ll,len-i+1);
            if(!(a[i]=='?'||b[i]=='?'))
            {

            }
            else if(a[i]=='?'&&b[i]!='?')
            {
                ll   fl=check(i+1,len);
               // cout<<ans<<" "<<fl<<endl;
                ll ma=maxp;
                int in=0;
                for(ll j=0; j<=9; j++)
                {

                    ll as=kop*j+ans+fl;
                    as-=kop*(b[i]-'0');
                    if(labs(as)<ma)
                    {
                        ma=labs(as);
                        in=j;
                    }
                }
                //cout<<ma<<endl;
                a[i]=48+in;

            }
            else if(b[i]=='?'&&a[i]!='?')
            {
                ll   fl=check(i+1,len);
                ll ma=maxp;
                int in=0;
                for(ll j=0; j<=9; j++)
                {
                    ll as=-PW(10ll,len-i+1)*j+ans+fl;
                    as+=kop*(a[i]-48);
                    if(labs(as)<ma)
                    {
                        ma=labs(as);
                        in=j;
                    }
                }
                b[i]=48+in;

            }
            else
            {
                //cout<<lol<<endl;
                ll   fl=check(i+1,len);
                ll ma=maxp;
                int u=0,v=0;
                for(int j=0;j<=9;j++)
                {

                    for(int k=0;k<=9;k++)
                    {
                        ll as=kop*j+ans+fl;
                        as-=kop*k;
                        if(labs(as)<ma)
                        {
                            ma=labs(as);
                            u=j;
                            v=k;
                        }

                    }
                }
                a[i]=48+u;
                b[i]=48+v;
            }
             ll x=len-i+1;
                ans+=PW(10ll,x)*(a[i]-'0');
                ans-=PW(10ll,x)*(b[i]-'0');
        }
        PC("Case #%d: ",++cs);
        PC("%s %s\n",a+st,b+en);
    }



}

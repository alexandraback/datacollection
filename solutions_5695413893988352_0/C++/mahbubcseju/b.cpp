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
string ok;
bool check(int n,string s)
{
    reverse(s.begin(),s.end());
    string s1=NTS(n);
    reverse(s1.begin(),s1.end());
    int x=s.size()-s1.size();
    for(int i=1;i<=x;i++)s1+='0';
    ok=s1;
    reverse(ok.begin(),ok.end());
//   if(n==20)cout<<s<<" "<<s1<<endl;
//   if(n==19)cout<<s<<" "<<s1<<endl;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='?'){

        }
        else if(s[i]!=s1[i])return false;
    }
    //if(n==20)cout<<s1<<s<<endl;
    return true;

}

int main()
{
R("in.txt");
W("out.txt");
    int tc,cs=0;
    I(tc);
    while(tc--)
    {
        string a,b;
        cin>>a>>b;
        int l=a.size();
        int l1=b.size();
        l=PW(10,l)-1;
        l1=PW(10,l1)-1;
        string ab,ab1,c,d;
        int ans=10000;
        for(int i=0; i<=l; i++)
        {

            if(!check(i,a))continue;

            c=ok;
           // if(i==19)lol;
            for(int j=0; j<=l1; j++)
            {
                if(!check(j,b))continue;
                d=ok;
                //if(i==19&&j==20)lol;
                //if(j==20)lol;
                if(abs(i-j)<ans){
                    ans=abs(i-j);
                    ab=c;
                    ab1=d;
                }

            }
        }
        PC("Case #%d: ",++cs);
        cout<<ab<<" "<<ab1<<endl;
    }

    return 0;
}

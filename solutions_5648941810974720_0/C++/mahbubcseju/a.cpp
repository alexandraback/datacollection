
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
string mp[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

int main()
{
    R("in.txt");
    W("out.txt");
    int tc,cs=0;
    I(tc);

    while(tc--)
    {
        char ch[2004];
        int a[200];
        SET(a);
        SC("%s",ch+1);
        int l=strlen(ch+1);
        for(int i=1;i<=l;i++)a[ch[i]]++;
        string s;
        while(a['G'])
        {
            s+='8';
            for(int i=0;i<mp[8].size();i++)a[mp[8][i]]--;


        }
        while(a['Z'])
        {
            s+='0';
            for(int i=0;i<mp[0].size();i++)a[mp[0][i]]--;


        }
         while(a['X'])
        {
            s+='6';
            for(int i=0;i<mp[6].size();i++)a[mp[6][i]]--;


        }
         while(a['S'])
        {
            s+='7';
            for(int i=0;i<mp[7].size();i++)a[mp[7][i]]--;


        }
         while(a['V'])
        {
            s+='5';
            for(int i=0;i<mp[5].size();i++)a[mp[5][i]]--;


        }
         while(a['U'])
        {
            s+='4';
            for(int i=0;i<mp[4].size();i++)a[mp[4][i]]--;


        }
         while(a['R'])
        {
            s+='3';
            for(int i=0;i<mp[3].size();i++)a[mp[3][i]]--;


        }
         while(a['W'])
        {
            s+='2';
            for(int i=0;i<mp[2].size();i++)a[mp[2][i]]--;


        }
         while(a['I'])
        {
            s+='9';
            for(int i=0;i<mp[9].size();i++)a[mp[9][i]]--;


        }
         while(a['O'])
        {
            s+='1';
            for(int i=0;i<mp[1].size();i++)a[mp[1][i]]--;


        }
        sort(s.begin(),s.end());
        PC("Case #%d: ",++cs);
        cout<<s<<endl;

    }



    return 0;
}

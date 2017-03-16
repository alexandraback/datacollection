#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#define si(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(int i=a;i>b;i--)
#define MOD 1000000007


/*inline long double log2(const long double x)
{
    return  log(x) * M_LOG2E;
}*/


using namespace std;
const int _limit=100001;
template <class T> inline T read()
{
    T ret=0;
    char c=gc();
    while(c<'0'||c>'9')
        c=gc();
    while(c>='0'&&c<='9')
    {
        ret=10*ret+c-48;
        c=gc();
    }
    return ret;
}

ll gcd2(ll a, ll b)
{
    ll r, i;
    while(b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t;
    t=read<int>();
    rep(i,0,t)
    {
        ll p, q;
        p=read<ll>();
        q=read<ll>();
        ll gcd=gcd2(p,q);
        p/=gcd;
        q/=gcd;
        ll pp=log2(p);
        if((q != 1) && (q & (q - 1)))
        {
            cout<<"Case #"<<i+1<<": impossible"<<endl;
        }
        else
        {
            while(pp>0)
            {
                p=pow(2,pp);
                ll gcd=gcd2(p,q);
                p/=gcd;
                q/=gcd;
                if(p==1)
                    break;
                ll pp=log2(p);
            }
            ll qq=log2(q);
            cout<<"Case #"<<i+1<<": "<<qq<<endl;
        }
    }
    return 0;
}

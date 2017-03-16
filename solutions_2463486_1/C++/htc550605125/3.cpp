#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<iostream>

using namespace std;

#ifdef DEBUG
int _msg_indent,_msg_cnt;
#define msg_head cerr.width(4),cerr<<_msg_cnt++<<__FUNCTION__<<'('<<__LINE__<<')'
#define msg(x) msg_head<<x<<endl
#else
#define msg(x)
#endif

template<typename T>
inline void maximize(T& a,const T b)
{ if (b>a) a=b; }
template<typename T>
inline void minimize(T& a,const T b)
{ if (b<a) a=b; }
template<typename T>
inline T maximum(const T& a,const T& b)
{ return a>b?a:b; }
template<typename T>
inline T minimum(const T& a,const T& b)
{ return a<b?a:b; }

typedef long long ll;

ll scan(){
    char ch;
    while (!isdigit(ch=getchar()));
    ll x=ch-'0';
    while (isdigit(ch=getchar()))
        x=x*10+ch-'0';
    return x;
}

int a[]= {1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001,0};

int work()
{
    int l=ceil(sqrt(scan())),r=floor(sqrt(scan())),*i=a,ans=0;
    msg(l<<' '<<r);
    while(*i)
    {
        if (*i >=l && *i <= r) ++ans;
        msg(*i);
        i++;
    }
    return ans;
}

int main(){
    int z=scan();
    for (int i=1;i<=z;++i)
    {
        cout<<"Case #"<<i<<": "<<work()<<endl;
    }
}

#include<cstdio>
#include<cstring>
#include<cctype>
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

int scan(){
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    while (isdigit(ch=getchar()))
        x=x*10+ch-'0';
    return x;
}

int g[107][107], maxx[107], maxy[107], n, m;

void init()
{
    n=scan(); m=scan();
    memset(maxx, 0, sizeof(maxx));
    memset(maxy, 0, sizeof(maxx));
    for (int i=0;i<n;++i)
    for (int j=0;j<m;++j)
    {
        int x = scan();
        g[i][j] = x;
        maximize(maxx[i], x);
        maximize(maxy[j], x);
    }
}

bool work()
{
    for (int i=0;i<n;++i)
    for (int j=0;j<m;++j)
    {
        if (g[i][j] == maxx[i]) continue;
        if (g[i][j] == maxy[j]) continue;
        return 0;
    }
    return 1;
}

int main(){
    int z=scan();
    for (int i=1;i<=z;++i)
    {
        init();
        cout<<"Case #"<<i<<": "<<(work()?"YES":"NO")<<endl;
    }
}

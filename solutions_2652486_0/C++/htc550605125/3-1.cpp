#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unordered_set>
#include<deque>

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

int t,r,n,m,k;

int a[100]={ 3,4,3 },b[100];

void init()
{
    for (int i=0;i<k;++i) 
        b[i]=scan();
}

void gen_random()
{
    for (int i=0;i!=n;++i)
        a[i] = (rand() % (m-1))+2;
}

bool check()
{
    deque<ll> Q0,Q1;
    unordered_set<ll> S;
    S.insert(1);
    for (int i=0;i!=n;++i)
    {
        Q1.clear();
        Q1.push_back(a[i]);
        S.insert(a[i]);
        for (auto j=Q0.begin();j!=Q0.end();++j)
        {
            Q1.push_back(*j);
            Q1.push_back(*j * a[i]);
            S.insert(*j * a[i]);
            msg(*j * a[i]);
        }
        Q0.swap(Q1);
    }
    for (int i=0;i!=k;++i)
        if (S.find(b[i]) == S.end()) return 0;
    return 1;
}

ll gen_ans()
{
    ll ans = 0;
    for (int i=0;i<n;++i)
        ans = ans * 10 + a[i];
    return ans;
}

ll work()
{
    init();
    while (1)
    {
        gen_random();
        if (check()) break;
        //cout<<"fail one"<<gen_ans()<<endl;
    }
    return gen_ans();
}

int main(){
    t=scan(), r=scan(), n=scan(), m=scan(), k=scan();
    srand(time(0));
    cout<<"Case #1:"<<endl;
    while (r--)
        cout<<work()<<endl;
}

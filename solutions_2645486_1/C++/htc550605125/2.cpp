#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
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

struct node
{
    ll e, v;
    node(ll E, ll V):e(E),v(V){ }
};

ll work()
{
    deque<node> Q;
    ll E=scan(),R=scan(),N=scan();
    minimize(R, E);
    Q.emplace_back(0,0);
    Q.emplace_back(E,0);
    while (N--)
    {
        ll V = scan();
        while (Q.size()>=2)
        {
            auto q0=Q.begin(),q1=q0+1;
            if (q0->e*V+q0->v > q1->e*V+q1->v) break;
            Q.pop_front();
        }
        auto q=Q.begin();
        Q.emplace_front(0, q->e*V+q->v);
        //regain
        for (auto i=Q.begin();i!=Q.end();++i)
            i->e += R;
        node last(0,0);
        while (Q.back().e > E) last=Q.back(), Q.pop_back();
        if (Q.back().e == E) continue;
        ll v0=Q.back().v, e0=Q.back().e, v1=last.v, e1=last.e;
        Q.emplace_back(E, v1+(v0-v1)/(e0-e1)*(E-e1));
    }
    return Q.front().v;
}

int main(){
    int z=scan();
    for (int i=1;i<=z;++i)
    {
        cout<<"Case #"<<i<<": "
            <<work()
            <<endl;
    }

}

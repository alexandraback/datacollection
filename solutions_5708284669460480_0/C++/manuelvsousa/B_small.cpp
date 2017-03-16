#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
//lista de binds
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
#define     fread(name)     freopen(name,"r",stdin)
#define     fwrite(name)    freopen(name,"w",stdout)
#define     sz(a)           (int)a.size()
#define     count_one       __builtin_popcount
#define     count_onell     __builtin_popcountll
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)

template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T sqr(T a){return a*a;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}

int K,TL,SL;
string keys;
string tword;

pii solucao(int idx,string s)
{
    if(idx==SL)
    {
        int resposta = 0;
        For(i,0,SL-TL)
        {
            if(!s.compare(i,TL,tword))resposta++;
        }
//        put(s," #end",resposta);
        return mp(resposta,resposta);
    }
    pii resposta = mp(0,-inf);
    For(i,0,K-1)
    {
        pii tmp = solucao(idx+1,s+keys[i]);
        resposta.sc = max(resposta.sc,tmp.sc);
        resposta.fs += tmp.fs;
    }
    return resposta;
}

int main()
{

    int T,t=1;
    cin>>T;
    while(T--)
    {
        cin >> K>> TL >> SL;
        cin>>keys;
        cin>>tword;
        pii resposta = solucao(0,"");
        double valor = (double)resposta.sc-double(resposta.fs)/double(pwr(K,SL));
        cout<<"Case #"<<t++<<": "<< setprecision(8)<< valor <<endl;
    }
    return 0;
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <list>
#include <vector>
#include <iomanip>
#include <cctype>
#include <complex>
#include <iterator>
#include <ostream>
#include <bitset>
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define clx complex<long double>
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;
int _bufint;
inline int in(){
    scanf("%d", &_bufint);
    return _bufint;
}
const ll LINF=~((1ll)<<63);
const int INF=~(1<<31);

struct trib{
    ll firsd;
    ll n;
    ll l, r;
    ll s;
    ll deld;
    ll deldist;
    ll dels;
};
struct att{
    ll curd;
    ll l, r;
    ll s;
};
bool comp(const att a, const att b){
    return a.curd<b.curd;
}

int main(){
#ifdef SSU
    freopen("bb4.in", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif

    srand(time(0));
    int T=in();
    for(int t=0;t<T;++t){
        ll x=in(), y=in();
        ll xx=x, yy=y;
        ll best=LINF;
        ll besti=0;
        for(int i=1;i<=10000;++i){
            if(std::abs(x)>std::abs(y)){
                if(x<0) x+=i;
                else x-=i;
            }else{
                if(y<0) y+=i;
                else y-=i;
            }
            if( std::abs(x)+std::abs(y)<best){
                best= std::abs(x)+std::abs(y);
                besti=i;
            }
        }
        for(int k=0;k<5000;++k){
            x=xx;
            y=yy;

            for(int i=1;i<=1000;++i){
                if(rand()&1){
                    if(x<0) x+=i;
                    else x-=i;
                }else{
                    if(y<0) y+=i;
                    else y-=i;
                }
                if( std::abs(x)+std::abs(y)<best){
                    best= std::abs(x)+std::abs(y);
                    besti=i;
                    //cout<<"ahtung"<<endl;
                   // cout<<besti+best*2<<endl;
                }
            }
        }

            ll ans=besti+best*2;


            printf("Case #%d: %lld\n", t+1, ans);



        }
        return 0;
    }


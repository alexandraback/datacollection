#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <bitset>
#define  pb push_back
#define mp make_pair
#define pii pair< pair<int,int> , pair<int,int> >
#define rep(i,s,n) for(int i=s;i<n;++i)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int buf_i;
int in(){
    scanf("%d", &buf_i);
    return buf_i;
}
const int INF=~(1<<31);
const ll LINF=~(1LL<<63);

const double eps=1e-6;
ll gcd(ll a, ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(){
#ifdef SSU
    freopen("cj3","r", stdin);
     freopen("cj3out.txt", "w", stdout);
#else
    //  freopen("g.in","r", stdin);
    // freopen("g.out", "w", stdout);
#endif

    int T=in();
    map<ll,int> m;
    for(int i=0;i<50;++i){
        m[1LL<<i]=i;
    }
   /* map<pair<int,int>,int > r;

    r[mp(1,1)]=1;
    r[mp(0,1)]=100000;
    for(int i=0;i<11;++i){
        map<pair<int,int>,int > rr=r;
        for(auto j=r.begin();j!=r.end();++j){
            for(auto h=r.begin();h!=r.end();++h){
                pair<int,int> a=j->first;
                pair<int,int> b=h->first;
                pair<int,int> c=mp(a.first*b.second+a.second*b.first, a.second*b.second);
                c.second*=2;
                int g=gcd(c.first,c.second);
                c.first/=g;
                c.second/=g;
                if(c.first<=10000 && c.second<=10000){
                    if(rr.count(c)==0){
                        rr[c]=std::min(j->second,h->second)+1;
                    }else{
                        rr[c]=std::min(std::min(j->second,h->second)+1,rr[c]);
                    }
                }
            }
        }
        r=rr;
    }*/
    for(int t=0;t<T;++t){
        printf("Case #%d: ",t+1);
        ll p,q;
        scanf("%lld/%lld",&p,&q);
        //gcd
        ll g=gcd(p,q);
        p/=g;
        q/=g;
        if(m.count(q)>0){
          //  int res=r[mp(p,q)]-1;
            //if(p!=1) --res;
            //printf("%d",res);

            int cur=m[q];
            int cc=m.upper_bound((ll)p)->second-1;
            cur-=cc;
            cout<<cur<<endl;
        }else{
            printf("impossible\n");
        }


    }
    fflush(stdout);







    return 0;
}

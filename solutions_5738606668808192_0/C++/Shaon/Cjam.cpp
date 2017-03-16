#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }

LL overflowmod(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

LL BigMod ( LL a, LL p, LL m ){
    LL res = 1;
    LL x = a;

    while ( p ){
        if ( p & 1 ){
            res = overflowmod( res , x , m );
        }
        x = overflowmod( x , x , m );
        p = p >> 1;
    }

    return res % m;
}


bool ispro(LL p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    LL s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        LL a=rand()%(p-1)+1;
        LL tmp=s;
        LL mod=BigMod(a,tmp,p);
        while( tmp!=p-1 && mod!=1 && mod!=p-1){
            mod=overflowmod(mod,mod,p);
            tmp *= 2;
        }
        if(mod!=p-1 && tmp%2==0){
            return false;
        }
    }
    return true;
}


LL pos(LL x){
    if ( ispro(x,5) )return 0;

    for (LL i=2;i*i<=x;++i){
        if ( x%i == 0 )return i;
    }
    exit(5);
}


set<int> ans;
set<int> vis;

vector<LL> dev[1<<16];


LL calc(int x,int b){
    LL p = 1;
    LL ret = 0;
    for (int i=0;i<16;++i){
        if ( x & (1<<i) ){
            ret += p;
        }
        p = p*b;
    }
    return ret;
}


int main(){

    freopen("cout.out","w",stdout);

    int lim = 50;

    while ( ans.size() < lim ){

        int mid = rand()%( 1<<14 );
        mid = mid<<1;
        mid += 1;
        mid += 1<<15;

        if ( vis.find( mid ) != vis.end() )continue;
        vis.insert( mid );
        bool ok=true;
        for (int i=2;i<=10;++i){
            LL val = calc( mid,i );
            LL x = pos(val);
            if ( x == 0 ){
                ok=false;
                break;
            }else{
                dev[ mid ].PB( x );
            }
        }
        if ( ok )ans.insert( mid );
    }

    printf("Case #%d:\n",1);
    for (auto p:ans){
        printf("%lld", calc(p,10) );
        for (LL &x:dev[p]){
            printf(" %lld",x);
        }
        printf("\n");
    }

    return 0;
}

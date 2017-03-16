#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include "BigInteger.cpp"

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

LL pos(bigint x){
    for (LL i=2;i<100000;++i){
        if ( x%i == 0 )return i;
    }
    return 0;
}


bigint calc(LL x,int b){
    bigint p("1");
    bigint ret("0");
    for (int i=0;i<32;++i){
        if ( x & (1LL<<i) ){
            ret += p;
        }
        p = p*b;
    }
    return ret;
}



map<LL,int> ans;
set<LL> vis;

vector<LL> dev[550];


LL get_rand(int x){

    LL ret = 0;
    while ( x-- ){
        ret <<= 1;
        if ( rand()%2 == 1 ){
            ret |= 1;
        }
    }
    return ret;
}

int main(){

    freopen("cout.out","w",stdout);


    int lim = 500;
    int cnt = 0;

    while ( ans.size() < lim ){

        LL mid = get_rand(30);
        mid = mid<<1;
        mid += 1;
        mid += (1LL<<31);

        if ( vis.find( mid ) != vis.end() )continue;
        vis.insert( mid );

        bool ok=true;
        vector<LL> shaon;
        for (int i=2;i<=10;++i){
            bigint val = calc( mid,i );
            LL x = pos(val);

            if ( x == 0 ){
                ok=false;
                break;
            }else{
                shaon.PB( x );
            }
        }
        if ( ok ){
            ans[mid] = cnt;
            dev[cnt] = shaon;
            cnt++;
        }

    }
    //cout<<ans.size()<<endl;

    printf("Case #%d:\n",1);
    for (auto p:ans){
        cout<< calc(p.X,10);
        for (LL &x:dev[p.Y]){
            printf(" %lld",x);
        }
        printf("\n");
    }

    return 0;
}

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


#define SIZE 1000001



int main(){

    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aout.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        LL n;
        scanf("%lld",&n);

        printf("Case #%d: ",kk);
        if ( n == 0 ){
            printf("INSOMNIA\n");
            continue;
        }

        int cnt[10] = {0};
        LL now = n;
        while ( true ){
            LL tmp = now;
            while ( tmp>0 ){
                cnt[tmp%10]++;
                tmp /= 10;
            }
            bool fnd = false;
            for (int i=0;i<10;++i){
                if ( cnt[i] == 0 )fnd = true;
            }
            if ( !fnd )break;

            now = now+n;
            assert( now>0 );
        }

        printf("%lld\n",now);
    }

    return 0;
}

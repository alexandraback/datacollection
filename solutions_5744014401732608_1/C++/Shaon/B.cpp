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

#define SIZE 55

int ans[SIZE][SIZE];
int n;

void print(){

    FO(i,0,n){
        FO(j,0,n){
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }

}

int main(){

    freopen("B-large.in","r",stdin);
    freopen("out.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d",&n);
        LL tar;
        scanf("%lld",&tar);

        printf("Case #%d: ",kk);

        if ( tar > ( 1LL<< (n-2) ) ){
            printf("IMPOSSIBLE\n");
            continue;
        }

        CLR(ans);

        for (int i=n-2;i>0;--i){
            for (int j=i+1;j<n;++j){
                ans[i][j] = 1;
            }
        }

        if ( tar == ( 1LL<< (n-2) ) ){
            for (int i=1;i<n;++i){
                ans[0][i] = 1;
            }
        }else{
            for (int i=1;i<n-1;++i){
                if ( ( tar & ( 1LL<< ( n-2-i ) ) ) > 0 ){
                    ans[0][i] = 1;
                }
            }
        }

        printf("POSSIBLE\n");
        print();


    }

    return 0;
}

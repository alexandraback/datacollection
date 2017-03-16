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


int main(){

    freopen("B-small-attempt0.in","r",stdin);
    freopen("bout.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);

        mint mp;

        int tmp;
        FO(i,0,n+n-1){
            FO(j,0,n){
                scanf("%d",&tmp);
                mp[tmp]++;
            }
        }

        vector<int> ans;
        for (auto p:mp){
            if ( p.Y %2 == 1 ){
                ans.PB( p.X );
            }
        }
        sort( ALL(ans) );

        printf("Case #%d:",kk);
        for (auto x:ans){
            printf(" %d",x);
        }
        printf("\n");


    }

    return 0;
}

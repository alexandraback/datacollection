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


struct PP{
    int a,b,c;
};

int main(){

    freopen("C-small-attempt2.in","r",stdin);
    freopen("out.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int a,b,c,lim;
        cin>>a>>b>>c>>lim;

        vector<PP> ans;

        int ac[11][11] ={0};
        int bc[11][11] ={0};

        for (int i=1;i<=a;++i){
            for (int j=1;j<=b;++j){
                int inc = 0;
                for (int k=1; k<=c && inc<lim ;++k){
                    if ( ac[i][k] >= lim ){
                        continue;
                    }
                    if ( bc[j][k] >= lim ){
                        continue;
                    }
                    ac[i][k]++;
                    bc[j][k]++;
                    inc++;
                    ans.PB( {i,j,k} );
                }
            }
        }

        printf("Case #%d: %d\n",kk,ans.size());
        for ( auto&p:ans ){
            printf("%d %d %d\n",p.a,p.b,p.c);
        }

    }


    return 0;
}

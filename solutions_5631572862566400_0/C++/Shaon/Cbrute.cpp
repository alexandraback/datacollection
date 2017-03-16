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

    //FRO
    freopen("C-small-attempt1.in","r",stdin);
    freopen("Cout.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int n;
        scanf("%d",&n);
        vector<int> per(n);
        FO(i,0,n)per[i] = i;

        vector<int> edge(n);
        FO(i,0,n){
            scanf("%d",&edge[i]);
            edge[i] --;
        }

        int ans = 1;
        do{

            FO(i,1,n){
                if ( edge [ per[i-1] ] == per[i]  ){
                    if ( edge[ per[i] ] == per[0] )
                        ans = max( ans, i+1 );
                }else{
                    break;
                }
            }

            FO(i,1,n){
                if ( edge[ per[i] ] == per[i-1] && edge[ per[i-1] ] == per[i] ){
                    int low = i-1;
                    while ( low-1>=0 && edge[ per[low-1] ] == per[low] ){
                        low--;
                    }
                    int high = i;
                    while ( high+1 <n && edge[ per[high+1] ] == per[high] ){
                        high++;
                    }
                    /*
                    show_c( per );
                    show(low,high);
                    */
                    ans = max( ans , high-low+1 );
                }
            }


        }while( next_permutation( ALL(per) ) );

        printf("Case #%d: %d\n",kk,ans);
    }


    return 0;
}

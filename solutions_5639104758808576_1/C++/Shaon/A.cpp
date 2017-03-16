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

#define SIZE 1010

int n;
char str[SIZE];


bool pos(int x){
    x +=  str[0]-'0';
    for (int i=1;i<=n;++i){
        if ( x >= i ){
            x += str[i]-'0';
        }else{
            return false;
        }
    }
    return true;
}

int main(){

    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%d %s",&n,str);

        int ans = -1;
        int low = 0,high = 100010;

        while ( low<=high ){
            int mid = (low+high)/2;
            if ( pos(mid) ){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }


        printf("Case #%d: %d\n",kk,ans);
    }

    return 0;
}

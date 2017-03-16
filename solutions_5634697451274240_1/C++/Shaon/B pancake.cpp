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

#define SIZE 110

char str[SIZE];
int n;

void my_rev(int a,int b){

    int x=a,y=b;
    while ( x<y ){
        swap( str[x],str[y] );
        x++,y--;
    }
    for (int i=a;i<=b;++i){
        str[i] = int('+') + int('-') - int(str[i]);
    }
}

int main(){

    freopen("B-large.in","r",stdin);
    freopen("bout.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%s",str);
        n = strlen(str);


        int ans = 0;
        for (int i=n-1;i>=0;--i){
            if ( str[i] == '-' ){
                if ( str[0] == '-' ){
                    my_rev( 0,i );
                    ans++;
                }else{
                    int tmp = 0;
                    while ( str[tmp] == '+' )tmp++;
                    tmp--;
                    my_rev( 0,tmp );
                    my_rev( 0,i );
                    ans += 2;
                }
            }
        }

        printf("Case #%d: %d\n",kk,ans);
    }

    return 0;
}

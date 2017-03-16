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


string alp[]={
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};



bool matcher(int* cnt,int x){

    int xxx[26]={0};
    for ( auto &s:alp[x] ){
        xxx[ s -'A' ]++;
    }
    FO(i,0,26)if ( xxx[i] > cnt[i] )return false;
    return true;
}

#define SIZE 100000

int ser[]={ 0 , 2 ,  4 ,  6 , 8 ,  3 ,  5 , 7 ,  1 , 9 };

char str[SIZE];

int main(){

    freopen("A-large.in","r",stdin);
    freopen("outA.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%s",str);
        int cnt[26]={0};

        for (int i=0;str[i];++i){
            cnt[ str[i]-'A' ]++;
        }

        int fnd[10]={0};
        while ( true ){

            int ind = -1;
            for (int i=0;i<10;++i){
                if ( matcher(cnt,ser[i]) ){
                    ind = ser[i];
                    break;
                }
            }
            if ( ind == -1 )break;

            fnd[ ind ]++;
            for ( auto& s:alp[ind] ){
                cnt[ s-'A' ]--;
            }

        }

        FO(i,0,10)assert( cnt[i] == 0 );

        printf("Case #%d: ",kk);
        for (int i=0;i<10;++i){
            while ( fnd[i] -- >0 ){
                printf("%d",i);
            }
        }
        printf("\n");

    }

    return 0;
}

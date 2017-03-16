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


pint mat[4][4]=
{
    { {1,0},{1,1},{1,2},{1,3} },
    { {1,1},{-1,0},{1,3},{-1,2} },
    { {1,2},{-1,3},{-1,0},{1,1} },
    { {1,3},{1,2},{-1,1},{-1,0} }
};


#define SIZE 10010

bool A[SIZE];
bool B[SIZE][SIZE];
bool C[SIZE];


char str[SIZE];
int get(char c){
    if ( c == '1' )return 0;
    else return c-'i'+1;
}

void mul( pint& a,pint b ){
    pint r = mat[ a.Y ][ b.Y ];
    a=  {  r.X* a.X*b.X , r.Y };
}

int len;

int main(){

    freopen("C-small-attempt4.in","r",stdin);
    freopen("out.out","w",stdout);


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        int L,X;
        scanf("%d %d",&L,&X);
        char xxx[SIZE];
        scanf("%s",xxx);
        str[0] = '\0';
        while ( X-- ){
            strcat( str,xxx );
        }
        len = strlen(str);

        for (int i=0;i<len;++i){
            for (int j=i;j<len;++j){
                B[i][j] = false;
            }
            A[i]=false;
            C[i]=false;
        }


        for (int i=0;i<len;++i){
            pint now = {1,0} ;
            for (int j=i;j<len;++j){
                mul ( now, { 1,get(str[j]) } );
                if ( now.X == 1 ){
                    if ( now.Y == 1 && i == 0 ){
                        A[j] = true;
                        //show( "A",i,j );
                    }else if ( now.Y == 2 ){
                        B[i][j] = true;
                        //show( "B",i,j );
                    }else if ( now.Y == 3 && j == len-1 ){
                        C[i] = true;
                        //show( "C",i,j );
                    }
                }
                //show( now.X,now.Y );
            }
            //break;
        }

        bool pos=false;

        for (int i=0;i<len;++i){
            for (int j=i+2;j<len;++j){
                if ( A[i] && B[i+1][j-1] && C [j] ){
                    pos=true;
                    i=j= SIZE+10;
                }
            }
        }

        if ( pos )printf("Case #%d: YES\n",kk);
        else printf("Case #%d: NO\n",kk);

    }


    return 0;
}

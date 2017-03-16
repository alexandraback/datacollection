#include <iostream> 
#include <map> 
#include <vector> 
#include <string> 
#include <set> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <queue> 
#include <list> 
#include <limits> 
#include <stack> 
#include <sstream> 
#include <fstream> 
#include <ctime> 
#include <cstdlib> 
#include <complex> 
#include <cctype> 
#include <iomanip> 
#include <functional> 
#include <cstring> 
using namespace std; 
 
typedef long long int64 ; 
typedef unsigned long long uint64 ; 
 
#define two(X) (1<<(X))  
#define twoL(X) (((int64)(1))<<(X)) 
#define PB push_back 
#define SZ(X) ((int)(X.size())) 
#define LEN(X) ((int)(X.length())) 
#define MP(X,Y) make_pair(X,Y)  
#define CLR(que)   while(!que.empty()) que.pop()  
#define CA(a, m, n) for(int ii=0; ii<m; ++ii){  for(int jj=0;  jj<n; ++jj)   cout<<a[ii][jj]<<" " ; puts("")  ;} 
 
inline int  lowbit(int n) { return n&(-n) ;} 

int dp[200][200]; 
int n,s,p; 
int data[100];   

int chkx (int x ){ 
    int res = x / 3 ; 
    if( x % 3 == 2 ) res += 2 ; 
    if( x % 3 == 1 ) res += 1 ; 
    if( x % 3 == 0 ) res += 1 ;
    if( res < 2 ) return -1  ;
    return res;
}

int chky( int x ) { 
    int res = x / 3 ; 
    if( x % 3 == 2 ) res += 1; 
    if( x % 3 == 1 ) res += 1;
    if( x % 3 == 0 ) ; 
    return res; 
}
int main (){
    freopen("in.txt","r",stdin) ; 
    freopen("out.txt","w",stdout); 
    int T ;
    cin >> T  ;
    for(int Cas = 1 ; Cas <= T; ++Cas){
        cin >> n >> s >> p ; 
        memset( dp, 0xff , sizeof(dp)) ; 
        dp[0][0]= 0; 
        for(int i = 0;  i < n ; ++i){ 
            cin >> data[  i ] ; 
            for(int j = 0 ; j <= s ; ++j){ 
                if(dp[i][j] == -1 ) continue ; 
                int x = chkx( data[ i ] ) , y = chky(data[i]) ;  
                if(data[i] >= 2){
                if( x >= p ){
                   // cout <<x<<" "<< i + 1<< endl; 
                    dp[i+1][j+1] = max( dp[i+1][j+1], dp[i][j]+1) ; 
                }else{
                    dp[i+1][j+1] = max( dp[i+1][j+1], dp[i][j] ) ; 
                } 
                }
                if( y >= p ) {
//                    cout << i + 1 << " "<< y << endl; 
                    dp[i+1][j] = max( dp[i+1][j] , dp[i][j]+1) ; 
                }else{  
                    dp[i+1][j] = max( dp[i+1][j], dp[i][j] ) ; 
                }
            }
//            cout << dp[ i + 1][ 0] << endl ;
        }

        int ans = max( dp[ n ][ s ], 0 ); 
        cout <<"Case #"<<Cas<<": "<< ans << endl; 
    }
    return 0; 
}



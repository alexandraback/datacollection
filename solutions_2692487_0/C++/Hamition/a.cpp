#include <iostream> 
#include <map> 
#include <vector> 
#include <cassert>
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

inline void open_file(){
    freopen("a.in", "r",stdin) ; 
    freopen("a.out", "w",stdout) ; 
}
int data[110],n;  
int b ; 
bool gao( int x ,int y){ 
    int pos = 1;
    int64 now = b ; 
    for( ; pos <= n ; ){ 
        if( data[pos] < now ) {
            now += data[pos] ;
            ++pos; 
        }else{
            if( x == 0 ) break; 
            now += now-1;
            --x; 
        }
    }
    return n - pos +1 <= y ; 
}


int main (){ 

    int T ;
    open_file() ; 
    cin >> T ; 
    for(int Cas = 1 ; Cas <= T ; ++Cas){
        int ans = 10000000;
        cin >> b ; 
        cin >> n ; 
        ans = n ; 
        for(int i=1; i<= n ; ++i){
            cin >> data[i] ;   
        }
        sort( data+1, data+1+n) ; 
        for(int i=0 ; i <= 100; ++i){ 
            for(int j=0; j <= 100; ++j){ 
                if( i + j >= n ) break ; 
                if(  gao( i , j ) ) ans = min( ans, i + j ) ;  
            }
        }
        
        cout <<"Case #"<<Cas<<": "<<ans <<endl ; 
    }
    return 0;
}
        

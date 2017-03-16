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

void open(){
    freopen( "a.in" , "r", stdin);
    freopen( "a.out", "w", stdout);
}

char ss[1000000+10]; 
int n; 
int to[1000]; 
int main (){
    
    open() ; 
    int T ; 
    cin >> T ;
    memset( to , 0 , sizeof(to)); 
    to['a'] = 1;
    to['e'] = 1;
    to['i'] = 1; 
    to['o'] = 1;
    to['u'] = 1;
    for(int Cas = 1 ; Cas <= T ; ++Cas){ 
        scanf ("%s%d", ss, &n ) ;  
      
        string s = string(ss) ; 
        int64 ans =0  ;
        int x = 0 , pre = -1;   
        for(int i=0 ; i < LEN(s) ; ++i){ 
            if( to[s[i]] == 1){ 
                x= 0 ; 
            }
            else x++; 
            if(x>= n ) pre = i ;
            ans = ans +  max( 0, (pre - n+ 2 ))  ;
        }
    
        cout <<"Case #"<<Cas<<": "<< ans << endl ; 
    }
    return 0;
}


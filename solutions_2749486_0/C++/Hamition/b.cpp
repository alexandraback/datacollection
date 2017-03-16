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
    freopen( "b.in" , "r", stdin);
    freopen( "b.out", "w", stdout);
}

int main (){
    
    open() ; 
    int T ; 
    cin >> T ;
    for(int Cas = 1 ; Cas <= T ; ++Cas){ 
         int x, y ; 
         cin >>x >> y ;  
         string s = ""; 
         for(int i= 1 ; i <= abs(x); ++i){
              if(x >0 ) s += "WE" ;
              else s += "EW";
         }
         for(int i=1; i <= abs(y) ; ++i){
             if( y > 0 ) s += "SN" ; 
             else s += "NS";
         }
         cout << "Case #"<<Cas <<": "<< s << endl ;
    }
    return 0; 
}
         

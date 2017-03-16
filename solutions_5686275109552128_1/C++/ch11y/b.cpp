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

const int maxn = 1000+10;
int dp[ maxn ][ maxn]; 
int main (){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout); 
    int T; 
    cin >> T; 
    
    for(int Cas = 1 ; Cas <= T ; ++Cas){

       int n ; cin >>n;
       vector < int > data(n); 
       for(int i = 0 ; i < n ; ++i)
           cin >> data[i];
       sort(data.begin(), data.end());
       int ans = data[n-1]; 
       for(int i=1; i <= 1000; ++i){ 
            int tmp = i; 
            for(int j = 0 ; j < n ; ++j){ 
                if( data[j] <= i ) 
                    continue; 
                int div = data[j] / i; 
                if(div * i < data[j] ) ++div; 
                tmp += div - 1; 
            }
            ans = min(ans, tmp); 
       }
       cout <<"Case #"<<Cas <<": "<< ans <<endl; 
    }
    return 0;
}


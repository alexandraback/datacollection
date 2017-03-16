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

int main (){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout); 
    int T; 
    cin >> T; 
    
    for(int Cas = 1 ; Cas <= T ; ++Cas){
        int n;
        cin >> n;
        string s;
        cin >> s; 
        int ans = 0;
        int cur = 0;
        for(int i = 0 ; i <= n ; ++i){ 
            if(s[i]=='0') 
                continue;
            
            if(cur < i ){ 
                ans += i - cur; 
                cur = i;
            }
            cur += s[i]-'0';
        }
        cout <<"Case #"<<Cas<<": "<< ans << endl; 
    }

    return 0;
}


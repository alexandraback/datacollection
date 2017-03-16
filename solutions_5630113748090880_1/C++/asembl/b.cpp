#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std ;
int hash[2501];

void work() {
     int N , min = 2501;
     
     cin >> N ;
     for ( int i = 0 ; i < N+N-1 ; ++i ) {
         for ( int j = 0 ; j < N ; ++j ) {
             int t ;
             cin >> t ;
             hash[t]^=1 ; 
         }
     }
     vector<int> ans ;
     ans.clear();
     for ( int i = 0 ; i < 2501 ; ++i )
         if (hash[i]==1) {
            hash[i]=0;
            ans.push_back(i);
         }
     for ( int i = 0 ; i < ans.size() ; ++i) {
         cout << ans[i] << ((i+1==ans.size()) ? '\n' : ' ');
     }
}

int main() {
    
    int T ;
    cin >> T ;
    for ( int cases = 1 ; cases <= T ; ++cases ) {
        cout << "Case #" << cases << ": "; 
        work();
    }
    
    return 0;
} 

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main(){
    //ios::sync_with_stdio(0);
    
    int TC;
    long long P,Q;
    char c;
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> P >> c >> Q;
        
        long long g = __gcd(P,Q);
        P /= g; Q /= g;
        
        cout << "Case #" << tc << ": ";
        
        if(__builtin_popcount(Q) == 1){
            P = P * ((1LL << 40) / Q);
            
            int ans = 40;
            
            while(P > 0){
                P /= 2;
                if(P > 0) --ans;
            }
            
            cout << ans << '\n';
        }else cout << "impossible\n";
    }
    
    return 0;
}

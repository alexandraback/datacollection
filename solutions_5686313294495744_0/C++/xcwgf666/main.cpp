#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

int tn, n;
string A[11111], B[11111];

int main () {
    
    cin >> tn;
    for(int ti = 1; ti <= tn; ti++) {
        
        cin >> n;
        for(int i = 0; i < n; i++) cin >> A[i] >> B[i];
        int ans = 0;
        for(int i = 1; i < (1 << n); i++) {
            set<string> gw1;
            set<string> gw2;
            bool fail = false;
            for(int j = 0; j < n; j++) if ((i & (1 << j)) == 0) {
                gw1.insert(A[j]);
                gw2.insert(B[j]);
            }
            int fa = 0;
            for(int j = 0; j < n; j++) if (i & (1 << j)) {
                ++fa;
                if (gw1.find(A[j])==gw1.end()) fail = true;
                if (gw2.find(B[j])==gw2.end()) fail = true;
                if (fail) break;
            }
            
            if (!fail)
                ans = max(ans, fa);
            
        }
        
        cout << "Case #" << ti << ": " << ans << endl;
        
    }
    
    return 0;
}
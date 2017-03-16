#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <iostream>
using namespace std;



int main() {
    //    freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        
        string S;
        cin >> S;
        
        string output;
        for (int i = 0; i < S.size(); i++) {
            
            if (i == 0) {
                output += S[i];
                continue;
            }
            if (output[0] > S[i]) {
                output += S[i];
            }
            else {
                output = S[i] + output;
            }
        }
        
        
        cout << "Case #" << z+1 << ": " << output << "\n";
        
    }
    

    
    return 0;
}


#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;



int main() {
    
    ofstream fout ("ans.txt");
    ifstream fin ("input.txt");
    
    int T;
    fin >> T;
    // TEST CASES
    for (int t = 0; t < T; t++) {
        int ans = 0;
        
        int R, C, W;
        fin >> R >> C >> W;
        for (int i = 0; i < C; i++) {
            if (i % W == W-1)
                ans++;
        }
        ans = ans * R;
        ans += W;
        
        if (C % W == 0)
            ans--;
        
        fout << "Case #" << t+1 << ": " << ans << "\n";
    }
    
    
    return 0;
}



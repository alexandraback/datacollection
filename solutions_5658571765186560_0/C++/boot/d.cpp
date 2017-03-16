
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string solve (int x, int r, int c) {

    bool ans = true;
    
    if (x >= 7) {
        ans = false;
    }
    else if (x > r && x > c) {
        ans = false;
    }
    else if (r * c % x != 0) {
        ans = false;
    }
    else if ((x + 1)/2 > min(r,c)) {
        ans = false;
    }
    else if (x == 1 || x == 2 || x == 3) {
        ans = true;
    } 
    else if (x == 4) {
        ans = min(r, c) > 2;
    }
    else if (x == 5) {
        ans = !(min(r, c) == 3 && max(r, c) == 5);
    }
    else if (x == 6) {
        ans = min(r, c) > 3;
    }
    
    return ans ? "GABRIEL" : "RICHARD";
}

int main(){
    
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);

    int t, x, r, c;
    cin >> t;    
    
    for (int cs = 1; cs <= t; cs++) {
        
        cin >> x >> r >> c;
        cout << "Case #" << cs << ": " << solve(x, r, c) << endl;
    }
    
    return 0;
}

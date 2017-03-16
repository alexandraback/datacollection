#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


int main() {
    int t;
    cin >> t;
    for (int q = 1; q <= t; ++q) {
        int r, c, w;
        cin >> r >> c >> w;
        int ans = 0;
        ans += (c / w) * (r - 1);
        ans += (c / w) - 1;
        ans += w + 1;
        if (c % w == 0) {
            --ans;
        } 

        cout << "Case #" << q << ": " << ans << endl; 
    }
    return 0;
}
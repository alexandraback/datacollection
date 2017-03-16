#include <iostream>
#include <cstdio>

using namespace std;

int T, r, c, w;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> T;
    int cur;
    for (int I = 0; I < T; I++) {
        cin >> r >> c >> w;
        cur = r * (c / w);
        if (c % w == 0) {
            cur += (w - 1);
        } else {
            cur += w;
        }
        
        cout << "Case #" << I + 1 << ": " << cur << '\n';
    }
}
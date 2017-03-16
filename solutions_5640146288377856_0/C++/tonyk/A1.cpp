#include <iostream>

using namespace std;


int main() {
    int t, r, w, c;
    int res, i;
    
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> r >> c >> w;
        res = 0;
        while (c > w) {
            res++;
            c -= w;
        }
        res += w;
        
        cout << "Case #" << i+1 << ": " << res << endl;
    }

    return 0;
}

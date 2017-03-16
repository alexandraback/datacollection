#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main() {
    int T; cin >> T;
    for (int zz=1; zz <= T; zz++) {
        ll r, t; cin >> r >> t;
        int n=0;
        while(true) {
            r++;
            if (t < (r*r-(r-1)*(r-1))) break;
            t -= (r*r-(r-1)*(r-1));
            n++;
            r++;
        }
        cout << "Case #" << zz << ": " << n << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int T;
int r, t;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> r >> t;
        cout << "Case #" << (i+1) << ": ";
        int k = 0, a = 0, v = 0;
        while (1) {
            int u = a+2*r+2*k+1;
            if (u > t) break;
            a = u;
            v++;
            k += 2;
        }
        cout << v << endl;
    }
}

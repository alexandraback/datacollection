#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int ni=0; ni<t; ni++) {
        uint64_t k, c, s;
        cin >> k >> c >> s;

        // Simple one
        uint64_t pos = 1;
        uint64_t x = 1;
        for (int i=0; i<c - 1; i++) x *= k;

        cout << "Case #" << (ni + 1) << ":";
        for (int i=0; i<k; i++) {
            cout << " " << pos;
            pos += x;
        }
        cout << endl;
    }
}

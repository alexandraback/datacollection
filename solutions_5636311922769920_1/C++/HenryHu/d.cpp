#include <iostream>
#include <cstdint>
#include <cassert>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int ni=0; ni<t; ni++) {
        uint64_t k, c, s;
        cin >> k >> c >> s;
        if (c * s < k) {
            cout << "Case #" << (ni + 1) << ": IMPOSSIBLE" << endl;
            continue;
        }
        uint64_t total = 1;
        for (int i=0; i<c; i++) total *= k;

        /*
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
        */
        cout << "Case #" << (ni + 1) << ":";
        int start = 1;
        for (int i=0; i<s; i++) {
            // check start .. start + c -1
            uint64_t pos = 1;
            int end = start + c - 1;
            if (end >= k) end = k;
            for (int j = start; j <= end; j++) {
                // check j
                pos = (pos - 1) * k + j;
            }
            cout << " " << pos;
//            assert(pos <= total);
            start += c;
            if (start > k) break;
        }
        cout << endl;
    }
}

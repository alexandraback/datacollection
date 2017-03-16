#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;


int main() {
    int t;
    cin >> t;
    for(int testcase(0); testcase != t; ++testcase) {
        cout << "Case #" << testcase + 1 << ": ";
        ull a, b, k;
        cin >> a >> b >> k;
        int pos = 0;
        for(ull i(0); i < a; ++i) {
            for(ull j(0); j < b; ++j) {
                if((i & j) < k) {
                    ++pos;
                }
            }
        }
        cout << pos << endl;
    }
}

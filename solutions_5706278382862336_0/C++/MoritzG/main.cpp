#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    double logconv = log(2);    
    for(int testcase(0); testcase != t; ++testcase) {
        cout << "Case #" << testcase + 1 << ": ";
        long long p, q;
        char dummy;
        cin >> p >> dummy >> q;
        double lq = log(q) / logconv;
        if(lq != floor(lq) || lq > 40) {
            cout << "impossible" << endl;
            continue;
        }
        int gen = 1;
        while(p * 2 < q) {
            p *= 2;
            ++gen;
        }
        cout << gen << endl;
    }
}

//
//  A.cpp
//  
//
//  Created by John Nevard on 5/10/14.
//
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<double> VD;

long gcd(long a, long b) {
    long r;
    while ((r = a % b) != 0) {
        a = b;
        b = r;
    }
    return b;
}

int pwr2(long q) {
    long pwr = 1;
    int expt = 0;
    for (; pwr < q; pwr <<= 1, ++expt) { }
    return (pwr == q ? expt : -1);
}

int main() {
    int nc;
    cin >> nc;
    for (int i = 1; i <= nc; ++i) {
        string pq;
        cin >> pq;
        long p, q;
        sscanf(pq.c_str(), "%ld/%ld", &p, &q);
        long d = gcd(p, q);
        p /= d;
        q /= d;
        int ng = pwr2(q);
        if (ng < 0)
            cout << "Case #" << i << ": impossible\n";
        else {
            for (; p >= 2; --ng) p /= 2;
            cout << "Case #" << i << ": "  << ng << '\n';
        }
    }
    return 0;
}

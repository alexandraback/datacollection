#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

long long f(long long A, int k) {
    return (A & ((1 << k))) + (1 << k) * ((A >> k) - 1) + (A >> k) + 1;
}

int main() {
    int T = 0;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        long long P, Q;
        char c;
        cin >> P >> c >> Q;
        vector<bool> p(int(sqrt(Q)+0.5)+1, true);
        p[0] = p[1] = false;
        for (size_t i = 2; i < p.size(); ++i) {
            if (! p[i])
                continue;
            for (size_t j = i*2; j < p.size(); j += i) {
                p[j] = false;
            }
            while (P % i == 0 && Q % i == 0) {
                P /= i;
                Q /= i;
            }
        }
        if (Q % P == 0) {
            Q /= P;
            P /= P;
        }
        int result = int(log(Q) / log (2) + 1e-6) - int(log(P) / log(2) + 1e-6);
        while (Q > 1 && Q % 2 == 0) {
            Q /= 2;
        }
        if (Q > 1)
            cout << "impossible";
        else
            cout << result;
        cout << endl;
    }
}

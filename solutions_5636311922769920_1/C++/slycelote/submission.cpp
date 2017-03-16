#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <istream>
#include <limits>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ":";
        ull K, C, S; cin >> K >> C >> S;
        if (C*S < K) {
            cout << " IMPOSSIBLE\n";
            continue;
        }
        vector<ull> p(C);
        p[0] = 1;
        for (ull i = 1; i < C; ++i)
            p[i] = p[i-1] * K;
        for (ull i = 0; i < K; i += C) {
            ull m = 0;
            for (ull j = 0; j < C; ++j)
                m += min(i+j, K-1) * p[j];
            cout << " " << (m + 1);
        }
        cout << "\n";
    }

    return 0;
}


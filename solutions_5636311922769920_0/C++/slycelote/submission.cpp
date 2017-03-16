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
        ull p = 1, m = 0;
        for (ull i = 0; i < C; ++i) {
            m += p;
            p *= K;
        }
        for (ull i = 0; i < K; ++i)
            cout << " " << (i * m + 1);
        cout << "\n";
    }

    return 0;
}


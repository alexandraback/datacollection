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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, J; cin >> N;
    cin >> N >> J;
    cout << "Case #1:\n";
    for (unsigned long long mask = 0; mask < J; ++mask) {
        string s(N-2, '0');
        for (int i = 0; i < N/2-1; ++i)
            s[i] = s[N-3-i] = '0' + !!(mask & (1ULL << i));
        s = string("1") + s + string("1");
        cout << s;
        for (int d = 3; d <= 11; ++d) {
            cout << ' ' << d;
#if 0
            if (stoull(s, nullptr, d-1) % d != 0) {
                cerr << s << " " << d << endl;
                return 1;
            }
#endif
        }
        cout << "\n";
    }

    return 0;
}


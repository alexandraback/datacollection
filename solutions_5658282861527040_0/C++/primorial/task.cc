#include <iostream>
#include <sstream> 
#include <cstdio>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
template<typename T> T ABS(const T& val) { return val < 0 ? -val : val; }


int main ()
{
    std::ios_base::sync_with_stdio(false);

    int T;
    while (cin >> T) {
        for (int test = 1; test <= T; ++test) {
            cout << "Case #" << test << ": ";

            int A, B, K;
            cin >> A >> B >> K;

            int ans = 0;
            for (int i = 0; i < A; ++i) {
                for (int j = 0; j < B; ++j) {
                    if ((i & j) < K) {
                        ++ans;
                    }
                }
            }

            cout << ans << "\n";
        }
    }


    return 0;
}

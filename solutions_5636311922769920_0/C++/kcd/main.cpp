#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>



using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }


void Solution() {
    LL k, c, s;
    cin >> k >> c >> s;
    LL cnt = 1;
    for (int i = 1; i < c; ++i) {
        cnt *= k;
    }
    for (int i = 1; i <= s; ++i) {
        cout << i * cnt << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
    }

    return 0;
}



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
    string s;
    cin >> s;
    while (!s.empty() && s.back() == '+') {
        s.pop_back();
    }
    if (s.empty()) {
        cout << 0 << endl;
        return;
    }
    int swaps = 0;
    for (size_t i = 0; i + 1 < s.length(); ++i) {
        if (s[i] != s[i + 1]) {
            ++swaps;
        }
    }
    cout << 1 + swaps << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
//        cerr << "Case #" << i + 1 << ": Done!" << endl;
    }

    return 0;
}



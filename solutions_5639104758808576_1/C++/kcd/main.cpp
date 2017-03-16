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


using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }


void Solution() {
    int n;
    string str;
    cin >> n >> str;
    vector<int> s(n + 1);
    for (int i = 0; i <= n; ++i) {
        s[i] = str[i] - '0';
    }

    for (int answer = 0; answer <= n; ++answer) {
        int cur = answer + s[0];
        bool all = true;
        for (int i = 1; i <= n; ++i) {
            if (cur >= i) {
                cur += s[i];
            } else if (s[i] > 0) {
                all = false;
                break;
            }
        }
        if (all) {
            cout << answer << endl;
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
    }

    return 0;
}



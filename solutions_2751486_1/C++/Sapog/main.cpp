#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// <editor-fold defaultstate="collapsed" desc="typedef ...">
typedef long long int64;
typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<int64, int64> pii64;
typedef unsigned long long uint64;
typedef vector<double> vd;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi; // </editor-fold>

constexpr double eps = 1e-11;
constexpr double pi  = acos(-1.0);
constexpr int    p   = 1000000007;

bool vowel(char c) {
    switch(c) {
        case 'a':
        case 'o':
        case 'u':
        case 'i':
        case 'e':
            return true;
    }
    return false;
}

void solve() {
    int n;
    string s;
    cin >> s >> n;
    int64 result = 0;
    int pos = -1;
    int new_pos = 0;
    int cur_cons = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (vowel(s[i])) {
            result += pos + 1;
            cur_cons = 0;
            new_pos = 0;
        } else {
            if (cur_cons == 0) {
                new_pos = i;
            }
            if (cur_cons == n) {
                result += pos + 2;
                pos++;
            } else if (cur_cons == n - 1) {
                cur_cons ++;
                pos = new_pos;
                new_pos = -1;
                result += pos + 1;
            } else {
                cur_cons ++;
                result += pos + 1;
            }
        }
    }
    cout << result << endl;
}

int main() {
    int nTests;
    cin >> nTests;

    for(unsigned int testNumber = 0; testNumber < nTests; ++testNumber) {
        printf("Case #%d: ", testNumber + 1);
        solve();
    }
    return 0;
}

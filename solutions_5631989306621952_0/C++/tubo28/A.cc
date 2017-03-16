#define _CRT_SECURE_NO_WARNINGS
// #define _GLIBCXX_DEBUG
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)

string s;

string solveSmall() {
    int n = s.size();
    string res = "";
    for (int S = 0; S < 1<<n; S++) {
        string tmp;
        for (int i = 0; i < n; i++) {
            if (S >> i & 1) {
                tmp += s[i];
            } else {
                tmp.insert(tmp.begin(), s[i]);
            }
        } 
        res = max(res, tmp);
    }
    return res;
}

string solveLarge() {
    int n = s.size();
    string cur;
    for (int i = 0; i < n; i++) {
        string a = cur;
        string b = cur;
        a += s[i];
        b.insert(b.begin(), s[i]);
        cur = a < b ? b : a;
    }
    return cur;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        string x = solveLarge();
        printf("Case #%d: %s\n", 1+i, x.c_str());
    }
}
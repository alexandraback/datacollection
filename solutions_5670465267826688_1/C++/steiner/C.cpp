#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
 
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
 
typedef long long int64;
 
using namespace std;

struct Q8 {
    int Sign;
    char Value;
    Q8 (char value)
        : Sign(1)
        , Value(value)
    {
    }
};

Q8 operator* (Q8 first, Q8 second) {
    Q8 result('1');
    result.Sign = first.Sign * second.Sign;
    if (first.Value == '1') {
        result.Value = second.Value;
        return result;
    }
    if (second.Value == '1') {
        result.Value = first.Value;
        return result;
    }
    if (first.Value == second.Value) {
        result.Sign *= -1;
        result.Value == '1';
    }
    if (first.Value == 'i' && second.Value == 'j') {
        result.Value = 'k';
    }
    if (first.Value == 'j' && second.Value == 'i') {
        result.Sign *= -1;
        result.Value = 'k';
    }
    if (first.Value == 'j' && second.Value == 'k') {
        result.Value = 'i';
    }
    if (first.Value == 'k' && second.Value == 'j') {
        result.Sign *= -1;
        result.Value = 'i';
     }
     if (first.Value == 'k' && second.Value == 'i') {
        result.Value = 'j';
     }
     if (first.Value == 'i' && second.Value == 'k') {
         result.Sign *= -1;
        result.Value = 'j';
     }
     return result;
}

void solve() {
    int64 L, X;
    cin >> L >> X;
    string S;
    cin >> S;
    string s;
    for (int i = 0; i < min(8 + X % 8, X); ++i) s += S;
    int n = sz(s);
    Q8 prefix('1');
    int left;
    for (left = 0; left < n; ++left) {
        prefix = prefix * Q8(s[left]);
        if (prefix.Sign == 1 && prefix.Value == 'i') {
            break;
        }
    }
    Q8 suffix('1');
    int right;
    for (right = n - 1; right >= 0; --right) {
        suffix = Q8(s[right]) * suffix;
        if (suffix.Sign == 1 && suffix.Value == 'k') {
             break;
        }
    }

    if (right <= left) {
        cout << "NO" << endl;
        return;
    }
    Q8 middle('1');
    for (int i = left + 1; i <= right - 1; ++i)
        middle = middle * Q8(s[i]);
    if (middle.Sign == 1 && middle.Value == 'j') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}

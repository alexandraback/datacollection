#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int k;
string str;

bool cons(char ch) {
    return (ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u');
}

int main() {
    int tests; cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        cin >> str >> k;
        long long res = 0;
        int last = -1;
        int cnt = 0;
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            if (cons(str[i])) ++cnt;
            else cnt = 0;
            if (cnt >= k) {
                last = i - k + 1;
            }
            res += last + 1;
        }
        cout << "Case #" << test_id << ": " << res << endl;
    }
    return 0;
}

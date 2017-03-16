#include <cstdio>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL long long
#define pii pair <int, int>
#define piii pair <pii, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

int main () {
    freopen ("A-large.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int T, cas = 1;
    cin >> T;
    while (T--) {
//        freopen ("in", "r", stdin);
        string s;
        cin >> s;
//        cout << s << endl;
        string now = "";
        for (int i = 0; s[i]; i++) {
            if (now + s[i] < s[i] + now) {
                now = s[i] + now;
            } else {
                now = now + s[i];
            }
//            cout << now << endl;
        }
        printf ("Case #%d: ", cas++);
        cout << now << endl;
    }
}

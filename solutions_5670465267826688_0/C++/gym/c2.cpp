
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
const int MAXLEN = 111111;
const string YES = "YES", NO = "NO";
const int m[5][5] = {{0, 1, 2, 3, 4}, {1, 1, 2, 3, 4}, {2, 2, -1, 4, -3}, {3, 3, -4, -1, 2}, {4, 4, 3, -2, -1}};

long long l, x, loop;
int seq[MAXLEN], mp[MAXLEN], mp2[MAXLEN];

int mul(int a, int b) {
    int neg = 0;
    if (a < 0) {
        a = -a;
        neg ^= 1;
    }
    if (b < 0) {
        b = -b;
        neg ^= 1;
    }
    if (neg) return -m[a][b];
    return m[a][b];
}
int factor(int b, int c) {
    int neg = 0;
    if (b < 0) {
        b = -b;
        neg ^= 1;
    }
    int a = 0;
    for (int i = 1; i < 5; i++) {
        if (m[i][b] == c) {
            a = i;
            break;
        } else if (m[i][b] == -c) {
            a = i;
            neg ^= 1;
            break;
        }
    }
    if (neg) return -a;
    return a;
}

bool solve() {
    string str;
    cin >> l >> x;
    cin >> str;
    int m = l * x;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= l; j++) seq[(i - 1)*l + j] = str[j - 1] - 'i' + 2;
    mp[0] = 1;
    for (int i = 1; i <= m; i++) mp[i] = mul(mp[i - 1], seq[i]);
    mp2[m] = seq[m];
    for (int i = m - 1; i > 0; i--)
        mp2[i] = mul(seq[i], mp2[i + 1]);
    if (mp[m] != -1) return false;
    for (int i = 1; i < m - 1; i++)
        for (int j = i + 2; j <= m; j++) {
            if (mp[i] == 2 && mp2[j] == 4) return true;
        }
    return false;
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        if (solve())
            cout << YES << endl;
        else
            cout << NO << endl;
    }
    return 0;
}

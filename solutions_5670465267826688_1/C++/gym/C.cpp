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
const int MAXLEN = 11111;
const string YES = "YES", NO = "NO";
const int m[5][5] = {{0, 1, 2, 3, 4}, {1, 1, 2, 3, 4}, {2, 2, -1, 4, -3}, {3, 3, -4, -1, 2}, {4, 4, 3, -2, -1}};

long long l, x, loop;
int seq[MAXLEN], mp[MAXLEN], mp2[MAXLEN], res[4];
bool used[10];
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

bool getAns(int cur, long long seg, int rhs) {
    if (cur == 2) {
        int i = seg % loop;
        int tmp = mul(res[i], rhs);
        int need = factor(tmp, cur);
        if (!used[need + 5]) return false;
        return true;
    }
    for (int i = 0; i < loop; i++) if (seg >= i) {
            int tmp = mul(res[i], rhs);
            int need = factor(tmp, cur);
            if (!used[need + 5]) continue;
            bool flag = getAns(cur - 1, seg - i, factor(need, mp2[l]));
            if (flag) return true;
        }
}

bool solve() {
    string str;
    cin >> l >> x;
    cin >> str;
    for (int i = 0; i < l; i++) seq[i + 1] = str[i] - 'i' + 2;
    mp[l] = seq[l];
    for (int i = l - 1; i > 0; i--) mp[i] = mul(seq[i], mp[i + 1]);
    mp2[0] = 1;
    for (int i = 1; i <= l; i++) mp2[i] = mul(mp2[i - 1], seq[i]);

    if (x == 1) {
        if (mp2[l] != -1) return false;
        int i1 = 1, i2 = l;
        while (i1 <= l && mp2[i1] != 2) i1++;
        while (i2 > 0 && mp[i2] != 4) i2--;
        if (i1 >= i2) return false;
        return true;
    }

    loop = 0;
    if (mp2[l] == 1) return false;
    else if (mp2[l] == -1) {
        loop = 2;
        res[1] = -1;
        res[0] = 1;
        if (x % loop == 0) return false;
    } else {
        loop = 4;
        res[0] = 1;
        res[1] = mp2[l];
        res[2] = -1;
        res[3] = -mp2[l];
        if (x % loop != 2) return false;
    }

    memset(used, false, sizeof(used));
    for (int i = 1; i <= l; i++) used[mp[i] + 5] = true;
    used[1 + 5] = true;
    if (getAns(4, x - 2, 1)) return true;
    return false;
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("clarge.out", "w", stdout);
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

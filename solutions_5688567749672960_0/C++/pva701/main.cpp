#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
long long next(long long x) {
    long long n = x;
    vector <int> digits;
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    sort(digits.begin(), digits.end());
    long long ret = 0;
    for (int i = digits.size() - 1; i >= 0; --i)
        ret = ret * 10 + digits[i];
    if (ret <= n)
        return n + 1;
    return ret;
}
long long next(long long x, long long n) {
    long long nn = n;
    long long xx = x;
    vector <int> digitsx;
    vector <int> digitsn;
    while (x) {
        digitsx.push_back(x % 10);
        x /= 10;
    }

    while (n) {
        digitsn.push_back(n % 10);
        n /= 10;
    }
    reverse(digitsn.begin(), digitsn.end());
    sort(digitsx.begin(), digitsx.end(), greater<int>());
    bool flag = false;
    long long ret = 0;
    for (int i = 0; i < digitsn.size(); ++i) {
        int j = 0;
        while (j < digitsn.size()) {
            long long res = ret * 10 + digitsx[j];
            for (int p = digitsx.size() - 1; p >= 0; --p)
                if (p != j) res = res * 10 + digitsx[p];
            if (res <= nn) break;
            ++j;
        }
        ret = ret * 10 + digitsx[j];
        digitsx.erase(digitsx.begin() + j);
    }
    if (ret <= xx)
        return xx + 1;
    return ret;
}

int len(long long x) {
    int ret = 0;
    while (x) {
        ret++;
        x /= 10;
    }
    return ret;
}

const int T = 1e8 + 10;
int d[T];

void solve() {
    for (int i = 0; i < T; ++i)
        d[i] = T;
    d[1] = 1;
    queue <int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v + 1 < T && d[v + 1] > d[v] + 1) {
            d[v + 1] = d[v] + 1;
            q.push(v + 1);
        }

        vector <int> dig;
        int vv = v;
        int res = 0;
        while (vv) {
            res = res * 10 + vv % 10;
            vv /= 10;
        }
        if (res < T && d[res] > d[v] + 1) {
            d[res] = d[v] + 1;
            q.push(res);
        }
    }
    /*cerr << "NOW " << n << endl;
    long long x = 1;
    int ans = 1;
    int lenN = len(n);
    while (len(x) != lenN) {
        x = next(x);
        ++ans;
    }
    //cerr << "x = " << x << endl;
    cerr << "n = " << n << "it = " << n << endl;
    cerr << "x = " << x << endl;
    while (x != n) {
        x = next(x, n);
        //cerr << "nx x = " << x << endl;
        ++ans;
    }
    cerr << "n = " << "it = " << n << endl;
    return ans;*/
}

int main() {
    //freopen("input.txt", "r", stdin);
    freopen("A-small-attempt5.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    //Comparator1 c1;
    //Comparator2 c2;
    solve();
    int t;
    cin >> t;
    long long n;
    for (int i = 1; i <= t; ++i) {
        cerr << " i = " << i << endl;
        int n;
        cin >> n;
        cout << "Case #" << i << ": " << d[n] << endl;
    }
    return 0;
}

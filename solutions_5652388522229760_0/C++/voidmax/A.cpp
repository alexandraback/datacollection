//#include "grader.h"
#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

typedef long long base;

string FileName = "input";

const int inf = 1e9;

int n;

base f(base K, base n, set <int> &di) {
    if (K == 0) return -1;
    base k = K;
    while (k != 0) {
        di.insert(k % 10);
        k /= 10;
    }
    if (K > 1e11) return -1;
    if (di.size() == 10) return K;
    return f(K + n, n, di);
}

int main() {
    //files(FileName);
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        cout << "CASE #" << i + 1 << ':' << ' ';
        int a; cin >> a;
        set <int> di;
        base ans = f(a, a, di);
        if (ans == -1) {
            cout << "INSOMNIA" << endl;
        } else {
            cout << ans << endl;
        }
    }
}

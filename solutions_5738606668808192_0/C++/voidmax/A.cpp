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

vector <int> rep;

int FastPow(int a, int i, int p) {
    int ans = 1;
    while (i != 0) {
        if (i & 1) {ans *= a; ans %= p;}
        a *= a; a %= p; i >>= 1;
        //cout << i << endl;
    }
    return ans;
}

int CheckPrime(vector <bool> &arr, int n) {
    if (arr.size() <= 9) {
        int ans = 0;
        Out(i, arr.size(), 0) {
            ans *= n;
            ans += arr[i];
        }
        int p = 3;
        while (p * p <= ans) {
            if (ans % p == 0) {
                rep.pb(p);
                return p;
            }
            p += 2;
        }
        return 0;
    }
    int p = 3;
    while (p < 500) {
        int ans = 0;
        For(i, 0, arr.size()) {
            if (arr[i]) ans += FastPow(n, i, p);
        }
        ans %= p;
        if (ans == 0) {
            rep.pb(p);
            return p;
        }
        p += 2;
    }
    return 0;
}

int CheckP(base a, int p) {
    vector <bool> arr;
    while (a != 0) {
        arr.pb(a & 1);
        a >>= 1;
    }
    return CheckPrime(arr, p);
}

int t, n, m;

bool CheckJ(base a) {
    vector <int> s; swap(s, rep);
    if (a % 2 == 0) return false;
    For(i, 2, 11) {
        int ans = CheckP(a, i);
        if (!ans) {
            //for(int j: rep) cout << j << ' '; cout << endl;
            return false;
        }
    }
    vector <bool> arr;
    while (a != 0) {
        arr.pb(a & 1);
        a >>= 1;
    }
    Out(i, arr.size(), 0) {
        cout << arr[i];
    }
    cout << ' ';
    for(int j: rep) cout << j << ' ';
    cout << endl; --m;
    return true;
}

int main() {
    //files(FileName);
    ios::sync_with_stdio(false);
    cin >> t;
    For(i, 0, t) {
        cout << "Case #" << i + 1 << ":\n";
        cin >> n >> m;
        base L = (base)1 << (n - 1), R = (base)1 << n;
        while (L < R && m) {
            CheckJ(L); ++L;
            //cout << L << endl;
        }
    }
}

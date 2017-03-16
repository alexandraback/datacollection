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


int n;

int check(string a) {
    int cnt = 0;
    For(i, 1, a.size()) {
        if (a[i] != a[i - 1]) {
            For(j, 0, i) {
                a[j] = a[i];
            }
            ++cnt;
        }
    }
    if (a[0] == '-') ++cnt;
    return cnt;
}


int main() {

    //files(FileName);
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        string a; cin >> a;
        cout << "Case #" << i + 1 << ':' << ' ';
        cout << check(a)<< endl;
    }
}

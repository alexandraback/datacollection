#include <iostream>
#include <string>
#include <memory.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <queue>
#include <list>

using namespace std;
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) for(int i=0;i<n;++i)
int get(char c) {
    if (c == 'i') return 2;
    if (c == 'j') return 3;
    return 4;
}

int q[12][12];

int mult(int a, int b) {
    int val = q[abs(a)][abs(b)];
    if (a < 0 && b > 0) val = -val;
    else if (a > 0 && b < 0) val = -val;
    return val;
}

int n, x;
string s;
int arr[20005];
int suf[20005];

void solve() {
    cin >> n >> x;
    cin >> s;
    for (int i = 0; i < n * x; ++i) {
        arr[i] = get(s[i % n]);
    }
    int len = n * x;
    int cur = 1;
    for (int i = len - 1; i >= 0; --i) {
        cur = mult(arr[i], cur);
        suf[i] = cur;
    }
    cur = 1;
    suf[len] = 1;
    for (int i = 0; i < len; ++i) {
        cur = mult(cur, arr[i]);
        if (cur == 2) {
            int now = 1;
            for (int j = i + 1; j < len; ++j) {
                now = mult(now, arr[j]);
                if (now == 3) {
                    if (suf[j + 1] == 4) {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
}



int main() {
    freopen("input.txt","r",stdin);
    //freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    q[1][1] = 1; q[1][2] = 2; q[1][3] = 3; q[1][4] = 4;
    q[2][1] = 2; q[2][2] = -1; q[2][3] = 4; q[2][4] = -3;
    q[3][1] = 3; q[3][2] = -4; q[3][3] = -1; q[3][4] = 2;
    q[4][1] = 4; q[4][2] = 3; q[4][3] = -2; q[4][4] = -1;
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int num = 0;
    while (T--) {
        num++;
        cout << "Case #" << num << ": ";
        solve();
    }
    return 0;
}

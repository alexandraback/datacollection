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

int go(int all, long long n) {
    if (n == 1) return all;
    if (n % 2 == 1) {
        int cur = all;
        int ret = go(all, n - 1);
        cur = mult(all, ret);
        return cur;
    }
    int cur = go(all, n / 2);
    cur = mult(cur, cur);
    return cur;
}

int n;
long long x;
string s;
int arr[20005];
int suf[20005];

void solve() {
   cin >> n >> x;
   long long len = 1LL * n * x;
   cin >> s;
   int all = 1;
   for (int i = 0; i < n; ++i) {
        arr[i] = get(s[i]);
        all = mult(all, arr[i]);
   }
   long long pos_s = -1;
   int cur = 1;
   for (int i = 0; i < 100 && pos_s == -1; ++i) {
        if (cur == 2) {
            pos_s = 1LL * n * i - 1;
            break;
        }
        if (i >= x) break;
        int cx = cur;
        for (int j = 0; j < n; ++j) {
            cx = mult(cx, arr[j]);
            if (cx == 2) {
                pos_s = 1LL * n * i + j;
                break;
            }
        }
        cur = mult(all, cur);
   }
   if (pos_s == -1) {
    cout << "NO" << endl;
    return;
   }

   long long pos_f = -1;
   cur = 1;
   for (int i = 0; i < 100 && pos_f == -1; ++i) {
        if (cur == 4) {
            pos_f = 1LL * n * x - 1 - 1LL * n * i + 1;
            break;
        }

        if (i >= x) break;
        int cx = cur;
        for (int j = n - 1; j >= 0; --j) {
            cx = mult(arr[j], cx);
            if (cx == 4) {
                int NUMBER = n * i + (n - j);
                pos_f = n * x - 1 - NUMBER + 1;
                break;
            }
        }
        cur = mult(cur, all);
   }
   if (pos_f == -1 || pos_f <= pos_s) {
    cout << "NO" << endl;
    return;
   }

   cur = 1;
   pos_s++; pos_f--;
   while (pos_s <= pos_f) {
  //  cout << pos_s << " " << pos_f << endl;
    if (pos_s % n == 0) {
        if (pos_f - pos_s + 1 >= n) {
            long long len = pos_f - pos_s + 1;
            len /= n;
            cur = mult(cur, go(all, len));
            pos_s += len * n;
        }
        else {
            cur = mult(cur, arr[pos_s % n]);
            pos_s++;
        }
    }
    else {
        cur = mult(cur, arr[pos_s % n]);
        pos_s++;
    }
   }
   if (cur == 3) {
    cout << "YES" << endl;
    return;
   }
   cout << "NO" << endl;
}



int main() {
   // freopen("input.txt","r",stdin);
    freopen("C-large.in","r",stdin);
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

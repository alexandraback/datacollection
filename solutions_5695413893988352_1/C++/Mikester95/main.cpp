#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxn 3010
#define inf 1000000000000000000LL

using namespace std;

struct sol {
    long long a, b;
    sol() {
        a = -1;
        b = -1;
    }

    void update0(long long newA, long long newB) {
        if (a == -1 || b == -1) {
            a = newA;
            b = newB;
        }
        if (abs(newA - newB) < abs(a - b)) {
            a = newA;
            b = newB;
        } else if (abs(newA - newB) == abs(a - b)) {
            if (newA < a) {
                a = newA;
                b = newB;
            } else if (newB < b) {
                a = newA;
                b = newB;
            }
        }
    }

    void update1(long long newA, long long newB) {
        if (a == -1 || b == -1) {
            a = newA;
            b = newB;
        }
        if (newA - newB > a - b) {
            a = newA;
            b = newB;
        } else if (newA - newB == a - b) {
            if (newA < a) {
                a = newA;
                b = newB;
            } else if (newB < b) {
                a = newA;
                b = newB;
            }
        }
    }

    void update2(long long newA, long long newB) {
        if (a == -1 || b == -1) {
            a = newA;
            b = newB;
        }
        if (newB - newA > b - a) {
            a = newA;
            b = newB;
        } else if (newB - newA == b - a) {
            if (newA < a) {
                a = newA;
                b = newB;
            } else if (newB < b) {
                a = newA;
                b = newB;
            }
        }
    }
};

void print(long long x, int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = x % 10;
        x /= 10;
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        cout << v[i];
    }
}

 void solve(int test) {
     string a, b;
     cin >> a >> b;

     sol dp[20][3];
     int len = a.length();
     dp[len][0].update0(0, 0);
     dp[len][1].update1(0, 0);
     dp[len][2].update2(0, 0);

     long long pw = 1;
     for (int i = len-1; i >= 0; --i) {
         vector<int> tr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
         for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                long long da = (a[i] != '?' ? a[i] - '0' : tr[j]);
                long long db = (b[i] != '?' ? b[i] - '0' : tr[k]);
                for (int m = 0; m < 3; ++m) {
                    dp[i][0].update0(da * pw + dp[i+1][m].a, db * pw + dp[i+1][m].b);
                    dp[i][1].update1(da * pw + dp[i+1][m].a, db * pw + dp[i+1][m].b);
                    dp[i][2].update2(da * pw + dp[i+1][m].a, db * pw + dp[i+1][m].b);
                }
            }
         }
         pw = pw * 10;
     }

     print(dp[0][0].a, len);
     cout << " ";
     print(dp[0][0].b, len);
 }

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test;
    cin >> test;

    for (int k = 1; k <= test; ++k) {
        cout << "Case #" << k << ": ";
        solve(k);
        cout << "\n";
    }
}

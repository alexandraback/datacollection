#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define getBit(x,i) ((x&(1<<i))>0)

typedef unsigned long long ull;
typedef long double ld;

template <class T> T sqr(T a) {
    return a * a;
}
template <class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

double nextDouble() {
    double x;
    scanf("%lf", &x);
    return x;
}

void LLtoStr(char * s, long long x) {
    int slen = 0;
    while (x) {
        s[slen++] = (x % 10) + '0';
        x /= 10;
    }
    if (slen == 0)
        s[slen++] = '0';
    reverse(s, s + slen);
    s[slen] = 0;
}

const int INF = int(1e9);
const long long LINF = (long long)(1e18);
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int dx[9] = {0, 0, 1, -1, 1, 1, -1, -1, 0},
                  dy[9] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

char ans[111][111];
bool met[111][111];

void solve() {
    memset(ans, '.', sizeof(ans));
    int n, m, k;
    n = nextInt<int>();
    m = nextInt<int>();
    k = nextInt<int>();
    bool swapped = false;
    if (n > m) {
        swap(n, m);
        swapped = true;
    }
    if (k == n * m - 1) {
        memset(ans, '*', sizeof(ans));
        ans[0][0] = 'c';
    }
    else
        if (n == 1) {
            int can = max(m - 1, 0);
            if (k > can) {
                puts("Impossible");
                return;
            }
            for (int j = m - 1; j >= m - k; j--)
                ans[0][j] = '*';
            ans[0][0] = 'c';
        }
        else
            if (n == 2) {
                int can = n * m - 2 * 2;
                if (k > can || k % 2 == 1) {
                    puts("Impossible");
                    return;
                }
                for (int j = m - 1; j >= m - (k / 2); j--)
                    ans[0][j] = ans[1][j] = '*';
                ans[0][0] = 'c';
            }
            else {
                int can = n * m - 2 * 2;
                if (k > can) {
                    puts("Impossible");
                    return;
                }
                memset(ans, '*', sizeof(ans));
                memset(met, 0, sizeof(met));
                int ost = n * m - k;
                int delta = 0;
                int x = 0, y = 0;
                int px, py;
                while (ost) {
                    if (ost == 1) {
                        bool fnd = false;
                        for (int i = 0; i < n && !fnd; i++)
                            for (int j = 0; j < m && !fnd; j++) {
                                if (ans[i][j]!='.') continue;
                                int k = 0;
                                for (int st = 0; st < 9; st++) {
                                    int xx = i + dx[st], yy = j + dy[st];
                                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && ans[xx][yy] == '*') {
                                        k++;
                                    }
                                }
                                if (k == ost) {
                                    fnd = 1;
                                    for (int st = 0; st < 9; st++) {
                                        int xx = i + dx[st], yy = j + dy[st];
                                        if (xx >= 0 && xx < n && yy >= 0 && yy < m && ans[xx][yy] == '*') {
                                            ost--;
                                            ans[xx][yy] = '.';
                                        }
                                    }
                                }
                            }
                        if (!fnd) {
                            puts("Impossible");
                            return;
                        }
                        break;
                    }
                    else {
                        bool fnd = false;
                        for (int i = 0; i < n && !fnd; i++)
                            for (int j = 0; j < m && !fnd; j++) {
                                if (ans[i][j]!='.') continue;
                                int k = 0;
                                for (int st = 0; st < 9; st++) {
                                    int xx = i + dx[st], yy = j + dy[st];
                                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && ans[xx][yy] == '*') {
                                        k++;
                                    }
                                }
                                if (k == ost) {
                                    fnd = 1;
                                    for (int st = 0; st < 9; st++) {
                                        int xx = i + dx[st], yy = j + dy[st];
                                        if (xx >= 0 && xx < n && yy >= 0 && yy < m && ans[xx][yy] == '*') {
                                            ost--;
                                            ans[xx][yy] = '.';
                                        }
                                    }
                                }
                            }
                        if (fnd) break;
                    }
                    met[x][y] = 1;
                    for (int st = 0; st < 9; st++) {
                        int xx = x + dx[st], yy = y + dy[st];
                        if (xx >= 0 && xx < n && yy >= 0 && yy < m && ans[xx][yy] == '*') {
                            ost--;
                            ans[xx][yy] = '.';
                        }
                    }
                    if (x == delta && y == delta) {
                        y++;
                        px = 0;
                        py = 1;
                    }
                    else
                        if (x == delta && y == m - delta - 1) {
                            x++;
                            px = 1;
                            py = 0;
                        }
                        else
                            if (x == n - delta - 1 && y == m - delta - 1) {
                                y--;
                                px = 0;
                                py = -1;
                            }
                            else
                                if (x == n - delta - 1 && y == delta) {
                                    x--;
                                    px = -1;
                                    py = 0;
                                }
                                else {
                                    x += px, y += py;
                                }
                    if (met[x][y]) {
                        x++, y++, delta++;
                    }
                }
                ans[0][0] = 'c';
            }
    if (swapped) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                putchar(ans[i][j]);
            }
            putchar('\n');
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                putchar(ans[i][j]);
            }
            putchar('\n');
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T = nextInt<int>();
    for (int i = 1; i <= T; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 55;
const string IMPOS = "Impossible";

void solve_1empty(int m, int n) {
    cout << string(1, 'c') << string(n-1, '*') << '\n';
    for (int i=1; i<m; ++i) {
        cout << string(n, '*') << '\n';
    }
}
void solve_line(int m, int n, int B) {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (B > 0) {
                cout << '*';
                --B;
            } else if (i==m-1 && j==n-1) {
                cout << 'c';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}
void solve_2(int m, int n, int empty) {
    assert(empty > 1);
    if (empty==2 || empty%2==1) {
        cout << IMPOS << '\n';
        return;
    }
    int B = m*n-empty;
    if (m == 2) {
        assert(n-1-B/2 >= 0);
        cout << string(B/2, '*') << string(n-1-B/2, '.') << "c\n";
        cout << string(B/2, '*') << string(n-B/2, '.') << '\n';
    } else {
        assert(n == 2);
        for (int i=0; i<B/2; ++i) {
            cout << "**\n";
        }
        for (int i=B/2; i<m-1; ++i) {
            cout << "..\n";
        }
        cout << "c.\n";
    }
}

bool notbomb[MAXN][MAXN];
void zero(int i, int j, int m, int n, int &empty) {
    for (int dr=-1; dr<=1; ++dr) {
        for (int dc=-1; dc<=1; ++dc) {
            int r = i + dr;
            int c = j + dc;
            if (r<0 || c<0 || r>=m || c>=n) continue;
            if (!notbomb[r][c]) {
                notbomb[r][c] = 1;
                empty -= 1;
            }
        }
    }
}
void output(int m, int n) {
    cout << 'c';
    for (int j=1; j<n; ++j) {
        cout << (notbomb[0][j] ? '.' : '*');
    }
    cout << '\n';
    for (int i=1; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cout << (notbomb[i][j] ? '.' : '*');
        }
        cout << '\n';
    }
}
void solve_general(int m, int n, int empty) {
    memset(notbomb, 0, sizeof notbomb);
    zero(0, 0, m, n, empty);
    assert(empty >= 0);
    for (int delta=1; empty>1 && delta+1<max(m, n); ++delta) {
        if (delta+1 < m) {
            int old = empty;
            zero(delta, 0, m, n, empty);
            assert(old-empty == 2);
        }
        if (empty>1 && delta+1<n) {
            int old = empty;
            zero(0, delta, m, n, empty);
            assert(old-empty == 2);
        }
    }
    for (int i=1; i<m-1 && empty>0; ++i) {
        for (int j=1; j<n-1 && empty>0; ++j) {
            int old = empty;
            zero(i, j, m, n, empty);
            assert(old-empty == 1);
        }
    }
    output(m, n);
}
void solve(int m, int n, int B) {
    int empty = m*n-B;
    if (empty == 1) {
        solve_1empty(m, n);
    } else if (min(m, n) == 1) {
        solve_line(m, n, B);
    } else if (min(m, n) == 2) {
        solve_2(m, n, empty);
    } else if (empty==2 || empty==3 || empty==5 || empty==7) {
        cout << IMPOS << '\n';
    } else {
        solve_general(m, n, empty);
    }
}
void solve() {
    int m, n, B;
    cin >> m >> n >> B;
    assert(B < m*n);
    solve(m, n, B);
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cout << "Case #" << t << ":\n";
        solve();
    }
	return 0;
}

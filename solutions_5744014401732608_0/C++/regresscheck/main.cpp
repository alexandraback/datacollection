#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;

int t;
long long b, m;

bool a[100][105];
void solve(long long b, long long m) {
    memset(a, 0, 100 * 100);
    for (int i = 1; i < b; ++i)
        for (int j = i + 1; j < b; ++j)
            a[i][j] = 1;
    long long k;
    a[1][b] = 1;
    --m;
    while (m > 0) {
        k = m & (-m);
        m -= k;
        int pos = 1;
        while (k > 0) {
            k >>= 1;
            ++pos;
        }
        if (pos >= b) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        a[pos][b] = 1;
    }
    cout << "POSSIBLE" << endl;
    for (int i = 1; i <= b; ++i) {
        for (int j = 1; j <= b; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void check(long long b, long long m) {
    long long p[55];
    p[1] = 1;
    for (int i = 2; i <= b; ++i) {
        p[i] = 0;
        for (int j = 1; j < i; ++j)
            if (a[j][i])
                p[i] += p[j];
    }
    if (p[b] == m)
        cout << "ZBS" << endl;
    else
        cout << "PIZDA " << p[b] << ' ' << m << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> b >> m;
        cout << "CASE #" << i << ": ";
        solve(b, m);
        //check(b, m);
    }
}

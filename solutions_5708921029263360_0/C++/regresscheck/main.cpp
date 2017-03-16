#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int jj, pp, ss, kk;

struct attempt {
    bool match[3][3][3];
    int cnt;
    attempt() {
        cnt = 0;
        memset(match, 0, 3 * 3 * 3);
    }
    bool goNext() {
        for (int i = 0; i < jj; ++i)
            for (int j = 0; j < pp; ++j)
                for (int k = 0; k < ss; ++k)
                    if (match[i][j][k] == 0) {
                        match[i][j][k] = 1;
                        ++cnt;
                        return true;
                    } else
                        match[i][j][k] = 0, --cnt;
        return false;
    }
    bool correct() {
        int met[3][3][3];
        memset(met, 0,  3 * 3 * 3 * sizeof(int));
        for (int i = 0; i < jj; ++i)
            for (int j = 0; j < pp; ++j)
                for (int k = 0; k < ss; ++k)
                    if (match[i][j][k]) {
                        ++met[0][i][j];
                        ++met[1][i][k];
                        ++met[2][j][k];
                    }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if (met[i][j][k] > kk)
                        return false;
        return true;
    }

    int count() {
        return cnt;
    }

    void print() {
        for (int i = 0; i < jj; ++i)
            for (int j = 0; j < pp; ++j)
                for (int k = 0; k < ss; ++k)
                    if (match[i][j][k])
                        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    }
};

void solve() {
    attempt a, best;
    int bestcnt = -1;
    while (a.goNext()) {
        if (a.count() > bestcnt && a.correct()) {
            bestcnt = a.count();
            best = a;
        }
    }
    cout << bestcnt << endl;
    best.print();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> jj >> pp >> ss >> kk;
        cout << "CASE #" << i << ": ";
        solve();
    }
}

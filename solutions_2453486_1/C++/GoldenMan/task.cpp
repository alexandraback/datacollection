#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

char a[4][4];

int test(char X) {
    int cnt;
    for (int i = 0; i < 4; ++i) {
        cnt = 0;
        for (int j = 0; j < 4; ++j) {
            if (a[i][j] == X || a[i][j] == 'T') ++cnt;
        }
        if (cnt == 4) return 1;
    }
    for (int i = 0; i < 4; ++i) {
        cnt = 0;
        for (int j = 0; j < 4; ++j) {
            if (a[j][i] == X || a[j][i] == 'T') ++cnt;
        }
        if (cnt == 4) return 1;
    }
    cnt = 0;
    for (int i = 0; i < 4; ++i) {
        if (a[i][i] == X || a[i][i] == 'T') ++cnt;
    }
    if (cnt == 4) return 1;
    cnt = 0;
    for (int i = 0; i < 4; ++i) {
        if (a[i][3 - i] == X || a[i][3 - i] == 'T') ++cnt;
    }
    if (cnt == 4) return 1;
    return 0;
}

void solve(int _case) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i][j] = getchar();
        }
        scanf("\n");
    }
    scanf("\n");
    if (test('X') && test('O')) {
        cerr << "ERROR!" << endl;
    }
    if (test('X')) {
        printf("Case #%d: X won\n", _case);
        return;
    }
    if (test('O')) {
        printf("Case #%d: O won\n", _case);
        return;
    }
    int full = 1;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (a[i][j] == '.') full = 0;
    if (full) {
        printf("Case #%d: Draw\n", _case);
        return;
    }
    printf("Case #%d: Game has not completed\n", _case);
}

int _;

int main() {
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf("%d\n", &_);
    for (int __ = 0; __ < _; ++__) {
        solve(__ + 1);
    }
    return 0;
}

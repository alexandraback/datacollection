#include <cstdio>
#include <string>
using namespace std;

int getnc() {
    int c;
    while (true) {
        c = getchar();
        if (c == -1) {
            throw "Error";
        }
        if (c != '.' && c!= 'X' && c != 'O' && c!= 'T') {
            continue;
        }
        break;
    }
    return c;
}

string solve() {
    const int n = 4;
    int map[4][4];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            map[i][j] = getnc();
        }

    for (int i = 0; i < n; ++i) {
        int cntr = 0;
        int cntc = 0;
        int cntw = 0;
        int cntv = 0;
        for (int j = 0; j < n; ++j) {
            cntr += (map[i][j] == 'X' || map[i][j] == 'T');
            cntc += (map[j][i] == 'X' || map[j][i] == 'T');
            cntw += (map[j][j] == 'X' || map[j][j] == 'T');
            cntv += (map[j][3-j] == 'X' || map[j][3-j] == 'T');
        }
        if (cntr == 4 || cntc == 4 || cntw == 4 || cntv == 4) {
            return "X won";
        }
    }

    for (int i = 0; i < n; ++i) {
        int cntr = 0;
        int cntc = 0;
        int cntw = 0;
        int cntv = 0;
        for (int j = 0; j < n; ++j) {
            cntr += (map[i][j] == 'O' || map[i][j] == 'T');
            cntc += (map[j][i] == 'O' || map[j][i] == 'T');
            cntw += (map[j][j] == 'O' || map[j][j] == 'T');
            cntv += (map[j][3-j] == 'O' || map[j][3-j] == 'T');
        }
        if (cntr == 4 || cntc == 4 || cntw == 4 || cntv == 4) {
            return "O won";
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (map[i][j] == '.')
                return "Game has not completed";

    return "Draw";
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int i = 1; i<=T;++ i) {
        printf("Case #%d: %s\n", i, solve().c_str());
    }
    return 0;
}

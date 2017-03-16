#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    short g[4][4];
    string s;
    long T;
    cin >> T;

    for (long t = 0; t < T; ++t) {
        for (short i = 0; i < 4; ++i) {
            cin >> s;
            for (short j = 0; j < 4; ++j)
                switch (s[j]) {
                    case '.':
                        g[i][j] = 0;
                        break;
                    case 'X':
                        g[i][j] = 1;
                        break;
                    case 'O':
                        g[i][j] = 2;
                        break;
                    case 'T':
                        g[i][j] = 3;
                        break;
                }
        }

        short flag = 0;
        for (short m = 1; m <= 2; ++m) {
            short i;
            for (i = 0; i < 4; ++i) {
                short j;

                for (j = 0; j < 4 && (g[i][j] & m); ++j);
                if (j == 4)
                    flag = 1;

                for (j = 0; j < 4 && (g[j][i] & m); ++j);
                if (j == 4)
                    flag = 1;
            }

            for (i = 0; i < 4 && (g[i][i] & m); ++i);
            if (i == 4)
                flag = 1;

            for (i = 0; i < 4 && (g[3 - i][i] & m); ++i);
            if (i == 4)
                flag = 1;

            if (flag == 1) {
                cout << "Case #" << (t + 1) << ": " << (m == 1 ? "X won\n" : "O won\n");
                break;
            }
        }

        if (flag)
            continue;

        for (short i = 0; i < 4 && !flag; ++i)
            for (short j = 0; j < 4 && !flag; ++j)
                if (g[i][j] == 0) {
                    cout << "Case #" << (t + 1) << ": Game has not completed\n";
                    flag = 1;
                }
        if (!flag)
            cout << "Case #" << (t + 1) << ": Draw\n";
    }
    return 0;
}


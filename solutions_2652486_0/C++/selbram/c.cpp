#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int nCases = 100;
    int junk;
    cin >> junk >> junk >> junk >> junk >> junk;
    printf("Case #1:\n");
    for (int cnum = 1; cnum <= nCases; cnum++) {
        bool cardsets[4][4][4];
        for (int r = 0; r < 100; r++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        cardsets[i][j][k] = true;
                    }
                }
            }
            /*for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        cout << i << " " << j << " " << k << " " << (cardsets[i][j][k] ? "true" : "false") << endl;
                    }
                }
            }*/
            for (int kk = 0; kk < 7; kk++) {
                int prod;
                cin >> prod;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        for (int k = 0; k < 4; k++) {
                            bool possible = false;
                            for (int mask = 0; mask < 8; mask++) {
                                int pend = 1;
                                if (mask & 1) pend *= (i+2);
                                if ((mask >> 1) & 1) pend *= (j+2);
                                if ((mask >> 2) & 1) pend *= (k+2);
                                //cout << pend << " = " << prod << endl;
                                if (pend == prod) possible = true;
                            }
                            //cout << "mark" << endl;
                            if (!possible) {
                                cardsets[i][j][k] = false;
                                //cout << "oh no!" << endl;
                            }
                        }
                    }
                }
            }
            /*for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        cout << i << " " << j << " " << k << " " << (cardsets[i][j][k] ? "true" : "false") << endl;
                    }
                }
            }*/
            bool broken = false;
            int i, j, k;
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    for (k = 0; k < 4; k++) {
                        if (cardsets[i][j][k]) {
                            broken = true;
                            break;
                        }
                    }
                    if (broken) break;
                }
                if (broken) break;
            }
            if (!broken) {
                cout << 1 << 1 << 1 << endl;
            } else {
                cout << (i+2) << (j+2) << (k+2) << endl;
            }
        }
    }
}

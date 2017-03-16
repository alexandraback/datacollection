#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define foreach(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair

int R, C, M;
char a[60][60];

void print() {
    a[0][0] = 'c';
    rep(i, R) {
        rep(j, C) printf("%c", a[i][j]);
        printf("\n");
    }
}
void print_error() {
    printf("Impossible\n");
}

int main() {
    int caseN;
    scanf("%d", &caseN);
    for (int caseI = 1; caseI <= caseN; caseI++)
    {
        printf("Case #%d:\n", caseI);

        scanf("%d %d %d", &R, &C, &M);
        rep(i, R) rep(j, C) a[i][j] = '*';
        if (M == R * C - 1) {
            print();
            continue;
        }
        if (R == 1) {
            for (int i = 1; i < C - M; i++) a[0][i] = '.';
            print();
        } else
        if (C == 1) {
            for (int i = 1; i < R - M; i++) a[i][0] = '.';
            print();
        } else {
            int rest = R * C - M, LLR, LLC;
            bool flag = false;
            for (int LR = 2; LR <= R && !flag; LR++)
                for (int LC = 2; LC <= C && !flag; LC++) {
                    if ((LR + LC - 2) * 2 <= rest && rest <= LR * LC) {
                        LLR = LR;
                        LLC = LC;
                        flag = true;
                    }
                }
            if (!flag) {
                print_error();
            } else {
                rest -= (LLR + LLC - 2) * 2;
                for (int i = 0; i < LLC; i++)
                    a[0][i] = a[1][i] = '.';
                for (int i = 2; i < LLR; i++) {
                    a[i][0] = a[i][1] = '.';
                    for (int j = 2; j < LLC; j++)
                        if (rest) a[i][j] = '.', rest--;
                }
                print();
            }
        }
    }
    return 0;
}

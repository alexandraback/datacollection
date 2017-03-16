#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <float.h>

using namespace std;

typedef long long ll;

//#define LARGE

char board[4][4];

string solve() {
    char player[] = {'X', 'O'};

    for (int p = 0; p < 2; p++) {
        stringstream s;
        s << player[p] << "  won";
        for (int j = 0; j < 4; j++) {
            bool win = true;
            for (int i = 0; i < 4; i++) {
                if (board[j][i] != player[p] && board[j][i] != 'T') {
                    win = false;
                    break;
                }
            }
            if (win) {
                return s.str();
            }
        }
        for (int i = 0; i < 4; i++) {
            bool win = true;
            for (int j = 0; j < 4; j++) {
                if (board[j][i] != player[p] && board[j][i] != 'T') {
                    win = false;
                    break;
                }
            }
            if (win) {
                return s.str();
            }
        }
        bool win = true;
        for (int i = 0, j = 0; i < 4; i++, j++) {
            if (board[j][i] != player[p] && board[j][i] != 'T') {
                win = false;
                break;
            }
        }
        if (win) {
            return s.str();
        }
        win = true;
        for (int i = 3, j = 0; i >= 0; i--, j++) {
            if (board[j][i] != player[p] && board[j][i] != 'T') {
                win = false;
                break;
            }
        }
        if (win) {
            return s.str();
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            if (board[j][i] == '.') {
                return "Game has not completed";
            }
        }
    }
    return "Draw";
}

int main() {

#ifndef LARGE
    FILE *in = fopen("A-small-attempt0.in", "r");
    FILE *out = fopen("A-small-attempt0.out", "w");
#else
    FILE *in = fopen("A-large-attempt.in", "r");
    FILE *out = fopen("A-large-attempt.out", "w");
#endif

    int T;
    fscanf(in, "%d", &T);
    for (int t = 0; t < T; t++) {
        for (int j = 0; j < 4; j++) {
            string s;
            fscanf(in, "%s", &s);
            for (int i = 0; i < 4; i++) {
                board[j][i] = s[i];
            }
        }
        fprintf(out, "Case #%d: %s\n", t + 1, solve().c_str());
    }
    fclose(in);
    fclose(out);
    return 0;
}

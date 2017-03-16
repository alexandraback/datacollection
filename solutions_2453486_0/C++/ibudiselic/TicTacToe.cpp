#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

char B[4][4];

void transpose() {
    for (int i=0; i<4; ++i) {
        for (int j=i+1; j<4; ++j) {
            swap(B[i][j], B[j][i]);
        }
    }
}
bool won(char c) {
    for (int foo=0; foo<2; ++foo) {
        for (int i=0; i<4; ++i) {
            bool ok = true;
            for (int j=0; j<4; ++j) {
                if (B[i][j]!=c && B[i][j]!='T') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return true;
            }
        }
        transpose();
    }
    bool ok = true;
    for (int i=0; i<4; ++i) {
        if (B[i][i]!=c && B[i][i]!='T') {
            ok = false;
            break;
        }
    }
    if (ok) {
        return true;
    }
    ok = true;
    for (int i=0; i<4; ++i) {
        if (B[i][3-i]!=c && B[i][3-i]!='T') {
            ok = false;
            break;
        }
    }
    return ok;
}
string solve() {
    if (won('O')) {
        return "O won";
    }
    if (won('X')) {
        return "X won";
    }

    int nfree = 0;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            nfree += (B[i][j] == '.');
        }
    }
    return nfree==0 ? "Draw" : "Game has not completed";
}
int main() {
    cin.sync_with_stdio(false);
    int ncases;
    scanf("%d", &ncases);
    for (int testcase=0; testcase<ncases; ++testcase) {
        getchar();
        for (int i=0; i<4; ++i) {
            for (int j=0; j<4; ++j) {
                B[i][j] = char(getchar());
            }
            getchar();
        }
        printf("Case #%d: %s\n", testcase+1, solve().c_str());
    }
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char mat[50][50];
bool ok = true;

void gao(int r, int c, int mine) {
    int blank = r * c - mine;
    memset(mat, '*', sizeof mat);
    ok = true;
    if ( mine == 0 ) {
        mat[0][0] = 'c';
    } if ( blank == 1 ) {
        mat[0][0] = 'c';
    } else if (1 == r) {
        mat[0][0] = 'c';
        for (int j = 1; j < blank; ++j) mat[0][j] = '.';
    } else {
        mat[0][0] = 'c';
        mat[0][1] = '.';
        mat[1][0] = '.';
        mat[1][1] = '.';
        blank -= 4;
        if ( blank < 0 ) {
            ok = false; return;
        }
        if ( blank == 0 ) return;

        if (2 == r) {
            if (blank % 2 == 1) {
                ok = false; return;
            }
            for (int j = 2; blank;++j, blank -= 2) {
                mat[0][j] = '.';
                mat[1][j] = '.';
            }
        } else {
            mat[2][0] = '.';
            mat[2][1] = '.';
            blank -= 2;
            if ( blank < 0 ) {
                ok = false; return;
            }
            if ( blank == 0 ) return;

            mat[0][2] = '.';
            mat[1][2] = '.';
            blank -= 2;
            if ( blank < 0 ) {
                ok = false; return;
            }
            if ( blank == 0 ) return;

            for ( int ir = 3; blank >= 2 && ir < r; ++ir ) {
                mat[ir][0] = '.';
                mat[ir][1] = '.';
                blank -= 2;
            }
            for ( int ic = 3; blank >= 2 && ic < c; ++ic ) {
                mat[0][ic] = '.';
                mat[1][ic] = '.';
                blank -= 2;
            }
            if ( 0 == blank ) return;
            if ( 1 == blank ) {
                mat[2][2] = '.';
                return;
            }
            for ( int ir = 2; ir < r; ++ir ) {
                for ( int ic = 2; ic < c; ++ic ) {
                    mat[ir][ic] = '.';
                    --blank;
                    if (0 == blank) return;
                }
            }
        }
    }
}

void solve(int ri) {
    int r, c, mine; cin >> r >> c >> mine;
    if ( r > c ) {
        swap(r, c);
        gao(r, c, mine);
        swap(r, c);
        for (int i = 0; i < 50; ++i) {
            for (int j = 0; j < 50; ++j) {
                if ( i < j ) swap(mat[i][j], mat[j][i]);
            }
        }
    } else {
        gao(r, c, mine);
    }
    printf("Case #%d:\n", ri);
    if ( !ok ) {
        puts("Impossible");
        return;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            putchar(mat[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
//    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    int re; cin >> re;
    for (int ri = 1; ri <= re; ++ri) solve(ri);
}

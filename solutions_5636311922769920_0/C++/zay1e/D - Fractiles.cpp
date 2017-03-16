#include <fstream>
#include <iostream>
#define ull unsigned long long
using namespace std;
fstream fsi("D-small-attempt0.in", fstream::in);
fstream fso("out.txt", fstream::out);

void solve() {
    ull c, i, j, k, l, pos, s, t;
    fsi >> t;
    for (i = 1; i <= t; i++) {
        fsi >> k >> c >> s;
        fso << "Case #" << i << ':';
        for (j = 1; j <= k; j++) {
            pos = j;
            for (l = 1; l < c; l++) {
                pos = k*(pos-1)+j;
            }
            fso << ' ' << pos;
        }
        fso << '\n';
    }
}

int main() {
    solve();
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int R, C, M;

void output(int w, int h, int r0, int r1) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 && j == 0)
                cout << 'c';
            else if (i < h)
                cout << (j<w ? '.' : '*');
            else if (i == h)
                cout << (j<r0 ? '.' : '*');
            else if (i == h+1)
                cout << (j<r1 ? '.' : '*');
            else
                cout << '*';
        }
        cout << endl;
    }
}

void output_impossible() {
    cout << "Impossible" << endl;
}

void solve() {
    cin >> R >> C >> M;
    cout << endl;
    
    if (M == R * C - 1) {
        output(1, 1, 0, 0);
        return;
    }

    if (R == 1) {
        output(C - M, 1, 0, 0);
        return;
    }
    if (C == 1) {
        output(1, R - M, 0, 0);
        return;
    }

    int dots = R * C - M;
    int width = min(C, dots / 2);

    if (width <= 1) {
        output_impossible();
        return;
    }
    int height = dots / width - 1;
    int r0 = width;
    int r1 = dots % width;
    if (r1 == 1) {
        if (height == 1) { 
            width --;
            r0 --;
            r1 += 2;
        } else {
            r0 --;
            r1 ++;
        }
        if (r1 > r0) {
            output_impossible();
            return;
        }
    }
    if (r1 > 0 && height + 2 > R) {
        output_impossible();
        return;
    }
    output(width, height, r0, r1);
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }

    return 0;
}

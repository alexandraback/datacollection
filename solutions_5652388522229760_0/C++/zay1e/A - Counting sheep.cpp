#include <fstream>
#include <iostream>
#define ull unsigned long long
using namespace std;
fstream fsi("A-small-attempt0.in", fstream::in);
fstream fso("out.txt", fstream::out);

const int mx = 10;
bool flags[10];
int cnt;

void clr() {
    int i;
    for (i = 0; i < mx; i++) flags[i] = false;
    cnt = 0;
}

void mark(int a) {
    while (a > 0) {
        if (!flags[a%10]) {
            flags[a%10] = true;
            cnt++;
        }
        a /= 10;
    }
}

void solve() {
    ull i, j, n, t;
    fsi >> t;
    for (i = 1; i <= t; i++) {
        fsi >> n;
        clr();
        if (n == 0) {
            fso << "Case #" << i << ": INSOMNIA" << '\n';
        } else {
            for (j = n; true; j += n) {
                if (j <= 0) cout << j << '\n';
                mark(j);
                if (cnt == 10) {
                    fso << "Case #" << i << ": " << j << '\n';
                    break;
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int t, n, a[1500], b[1500], solved[1500];

void solve(int c) {
    int stars = 0, k = 0;
    for (int i = 0; i < 1500; ++i) solved[i] = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    while (true) {
        int v = -1, g = -1;
        for (int i = 0; i < n; ++i) {
            if ((solved[i] != 2) && (stars >= b[i])) g = i;
            else if ((solved[i] == 0) && (stars >= a[i]) && ((v == -1) || (b[i] > b[v]))) v = i;
        }
        if (g != -1) {
            stars += (2 - solved[g]);
            ++k;
            solved[g] = 2;
            continue;
        }
        if (v != -1) {
            ++stars;
            ++k;
            solved[v] = 1;
            continue;
        } else {
            for (int j = 0; j < n; ++j) {
                if (solved[j] != 2) {
                    cout << "Case #" << c << ": Too bad\n";
                    return;
                }
            }
            cout << "Case #" << c << ": " << k << endl;
            return;
        }
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) solve(i+1);

    return 0;
}

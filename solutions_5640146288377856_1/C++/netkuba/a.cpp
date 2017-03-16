#include <cstdio>
#include <iostream>

using namespace std;

void solve(int t) {
    int r, c, w;
    cin >> r >> c >> w;
    
    int solution = 0;
    solution += (r - 1) * (c / w);
    if (c != w) {
        solution += (c - w - 1) / w + 1;
    }
    solution += w;

    printf("Case #%d: %d\n", t, solution);
}

int main() {
    int t;
    cin >> t;
    for (int tt=1; tt<=t; ++tt) {
        solve(tt);
    }
}

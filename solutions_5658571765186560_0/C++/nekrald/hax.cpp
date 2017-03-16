#include <bits/stdc++.h>
using namespace std;

string solve() {
    int x, r, c; scanf("%d%d%d", &x, &r, &c);
    if (r > c) swap(r, c); // c = max(r, c)
    if ((x >= 7) || (((r * c) % x) != 0) || (c < x && r < x) || (min(r, c) < ( (x + 1) / 2 ))) return "RICHARD";
    if (c >= x + 1 || r >= x + 1) return "GABRIEL";
    assert(c == x);
    int t = r;
    if (x == 1 || x == 2) return "GABRIEL";
    bool gabr = true;
    if (x == 3 && t < 2) gabr = false;
    if (x == 4 && t < 3) gabr = false;
    if (x == 5 && t < 4) gabr = false;
    if (x == 6 && t < 4) gabr = false;
    if (gabr) {
        return "GABRIEL";
    } else {
        return "RICHARD";
    }
}


int main() {
    int T; scanf("%d", &T);
    for (int _ = 1; _ <= T; ++_) {
        printf("Case #%d: ", _);
        puts(solve().c_str());
    }
}

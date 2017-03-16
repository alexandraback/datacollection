#include <iostream>
#include <algorithm>
using namespace std;

void solve(int ri) {
    double C, F, X; cin >> C >> F >> X;
    double Best = 1e20;
    double Base = 0;
    for ( int i = 0; ;++i ) {
        double Cur = Base + X / (2 + i * F);
        if ( Cur < Best ) Best = Cur;
        Base += C / (2 + i * F);
        if ( Base > Best ) break;
    }
    printf("Case #%d: %.15f\n", ri, Best);
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int re; cin >> re;
    for (int ri = 1; ri <= re; ++ri) solve(ri);
}

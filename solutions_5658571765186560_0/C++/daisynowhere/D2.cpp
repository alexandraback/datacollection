#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;

int Tc, x, r, c;

bool gao(int x, int r, int c) {
    if (x == 1) return true;
    if (x == 2) {
        return
        (r == 1 && c == 2) ||
        (r == 1 && c == 4) ||
        (r == 2 && c == 2) ||
        (r == 2 && c == 3) ||
        (r == 2 && c == 4) ||
        (r == 4 && c == 4) ||
        (r == 3 && c == 4); 
    }
    if (x == 3) {
        return
        (r == 2 && c == 3) ||
        (r == 3 && c == 3) ||
        (r == 3 && c == 4);
    }
    if (x == 4) {
        return
        //(r == 2 && c == 4) ||
        (r == 3 && c == 4) ||
        (r == 4 && c == 4);
    }
    throw 0;
}

int main() {
    cin >> Tc;
    rep (ri, Tc) {
        printf("Case #%d: ", ri + 1);
        cin >> x >> r >> c;
        if (r > c) swap(r, c);
        puts(gao(x, r, c) ? "GABRIEL" : "RICHARD");
    }
}


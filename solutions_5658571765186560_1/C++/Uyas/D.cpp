#include <cstdio>
#include <algorithm>
using namespace std;

int x, r, c;

bool check_s3x5(int l) {
    return l % 5 == 0;
}

bool blocked() {
    if (r * c % x != 0) return true; // rc is not a multiple of x
    int l = max(r, c), s = min(r, c);
    if (x > l) return true; // straight 1*x out of boundary
    if (s < (x+1) / 2) return true; // cant contain the big L
    if (x >= 7 && s >= 3) return true; // a hole in the Nomino
    if (s == 2 && x >= 4) return true; 
    if (s == 3 && x == 5 && check_s3x5(l)) return true;
    if (s == 3 && x >= 6) return true;
    return false;
}

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        scanf("%d%d%d", &x, &r, &c);
        printf("Case #%d: ", cas);
        if (blocked()) 
            puts("RICHARD");
            else puts("GABRIEL");
    }
    return 0;
}

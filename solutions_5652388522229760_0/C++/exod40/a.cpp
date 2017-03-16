#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n;

void read() {
    scanf("%d", &n);
}

void add(int x, int &y) {
    while (x) {
        y |= (1 << (x % 10));
        x /= 10;
    }
}

void solve() {
    int s = n;
    int mask = 0;
    for (int i = 0; i < 10000; i++) {
        add(s, mask);
        if (mask == (1 << 10) - 1) {
            printf ("%d\n", s);
            return;
        }
        s += n;
    }

    printf ("INSOMNIA\n");
}

int main() {
    int cases;

    scanf("%d", &cases);
    for (int i=1; i<=cases; i++) {
        read();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}


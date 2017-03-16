#include <cstdio>
#include <vector>
using namespace std;
const int NMAX = 1000505;
int tests;
long long cnt[NMAX];

void update(long long x, int& mark) {
    while (x) {
        mark |= (1 << (x % 10));
        x /= 10;
    }
}

void go(int x) {
    long long curr = x;
    int mark = 0;
    update(curr, mark);

    while (mark != (1 << 10) - 1) {
        curr += x;
        update(curr, mark);
    }

    cnt[x] = curr;
}

void precompute() {
    cnt[0] = -1;
    for (int i = 1; i < NMAX; i++) {
        go(i);
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    precompute();

    scanf("%d", &tests);
    int x;
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);
        scanf("%d", &x);
        if (cnt[x] == -1) {
            printf("INSOMNIA\n");
        } else {
            printf("%lld\n", cnt[x]);
        }
    }
    return 0;
}
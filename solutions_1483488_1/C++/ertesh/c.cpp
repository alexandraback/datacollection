#include <cstdio>
#include <iostream>
using namespace std;

void solve(int te) {
    int A, B;
    scanf("%d %d", &A, &B);
    long long ret = 0;
    int p = 1;
    while (p <= A) p *= 10;
    p /= 10;
    for (int i = A; i < B; i++) {
        if (i == 10 * p) p *= 10;
        int k = i;
        while (true) {
            k = 10 * (k % p) + (k / p);
            if (k == i) break;
            if (k > i && k <= B) ret++;
        }
    }
    printf("Case #%d: %lld\n", te, ret);
}

int main() {
    int te;
    scanf("%d", &te);
    for (int i = 1; i <= te; i++) {
        solve(i);
    }
}

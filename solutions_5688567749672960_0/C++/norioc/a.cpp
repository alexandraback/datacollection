#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <map>

using namespace std;

struct D {
    int n;
    int step;
};

int reverse(int n) {
    int x = 0;
    while (n > 0) {
        x = 10*x + (n % 10);
        n /= 10;
    }
    return x;
}

int calc(long long n) {
    map<int, int> used;

    queue<D> q;
    q.push((D){ 1, 1 });
    while (!q.empty()) {
        D d = q.front();
        q.pop();

        if (d.n == n) return d.step;
        if (used[d.n]++) continue;

        q.push((D){ d.n+1, d.step+1 });
        q.push((D){ reverse(d.n), d.step+1 });
    }
    assert(false);
    return 0;
}

int main() {
    int ncases;
    cin >> ncases;

    for (int cc = 0; cc < ncases; cc++) {
        long long x;
        cin >> x;
        long long ans = calc(x);
        printf("Case #%d: %d\n", cc+1, calc(x));
    }
}

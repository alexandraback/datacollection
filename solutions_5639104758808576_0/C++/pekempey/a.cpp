#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
int a[1001];

template<class T, int N>
class BIT {
    int n;
    T bit[N + 1];
    public:
    BIT() {
        for (int i = 0; i < N + 1; i++) {
            bit[i] = 0;
        }
    }
    void add(int k, T x) {
        k++;
        while (k <= N) {
            bit[k] += x;
            k += k & -k;
        }
    }
    T sum(int k) {
        k++;
        T res = 0;
        while (k > 0) {
            res += bit[k];
            k -= k & -k;
        }
        return res; 
    }
    T sum(int a, int b) {
        return sum(a) - sum(b - 1);
    }
    T get(int k) {
        return sum(k) - sum(k - 1);
    }
    void update(int k, T x) {
        add(k, x - get(k));
    }
    void init() {
        fill_n(bit, N + 1, 0);
    }
};

BIT<int, 1001> bit;

int solve() {
    int ans = 0;

    bit.init();
    for (int i = 0; i <= n; i++) {
        bit.add(i, a[i]);
    }

    for (int i = 1; i <= n; i++) {
        int sum = bit.sum(i - 1);
        if (a[i] > 0 && sum < i) {
            ans += i - sum;
            bit.add(i - 1, ans);
        }
    }

    return ans;
}

int main() {
    int q;
    cin >> q;

    for (int j = 1; j <= q; j++) {
        string s;
        cin >> n >> s;

        for (int i = 0; i <= n; i++) {
            a[i] = s[i] - '0';
        }

        int ans = solve();

        printf("Case #%d: %d\n", j, ans);
    }
}

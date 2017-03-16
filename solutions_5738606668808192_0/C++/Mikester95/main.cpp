#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

void print(long long conf, int n) {
    for (int i = n-1; i >= 0; --i) {
        cout << (((conf>>i)&1) ? 1 : 0);
    }
}

long long parseInBase(long long conf, int n, int b) {
    long long ans = 0;
    for (int i = n-1; i >= 0; --i) {
        ans = ans * b + (((conf>>i)&1) ? 1 : 0);
    }
    return ans;
}

void solve(int n, int k) {
    long long start = (1<<(n/2-1)) + 1;

    for (long long conf = start, i = 1; i <= k; conf += 2, i += 1) {
        long long nr = (conf<<(n>>1)) + conf;
        print(nr, n);
        cout << " ";
        for (int b = 2; b <= 10; ++b) {
            cout << parseInBase(conf, n, b) << " ";
        }
        cout << "\n";
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test, n, k;
    cin >> test;
    cin >> n >> k;
    cout << "Case #" << 1 << ":\n";
    solve(n, k);
}

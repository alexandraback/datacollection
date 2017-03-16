#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define INF 1000000000
#define min(x, y) (x < y ? x : y)

using namespace std;

long f(long &curW, long targetW) {
    long ans = 0;

    while (curW <= targetW) {
        curW += curW - 1;
        ans++;
    }
    curW += targetW;

    return ans;
}

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long T;
    cin >> T;

    for (long t = 0; t < T; ++t) {

        long a, n;
        cin >> a >> n;
        vector<long> w(n), ops(n);

        for (long i = 0; i < n; ++i)
            cin >> w[i];
        sort(w.begin(), w.end());

        if (a == 1) {
            printf("Case #%ld: %ld\n", t + 1, n);
            continue;
        }

        long curW = a;
        for (long i = 0; i < n; ++i)
            ops[i] = f(curW, w[i]) + (i == 0 ? 0 : ops[i - 1]);

        long ans = n;

        for (long i = 0; i < n; ++i)
            ans = min(ans, ops[i] + (n - i - 1));

        printf("Case #%ld: %ld\n", t + 1, ans);
    }
}
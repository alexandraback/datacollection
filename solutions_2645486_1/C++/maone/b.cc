#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int N, v[10000];
long long E, R;

long long solve(int left, int right, int in, int out) {
    if (left == right) {
        assert(in >= out);
        return 0;
    }

    int k = max_element(v + left, v + right) - v;
    int mv = v[k];

    long long maxin = min(in + (k - left) * R, E);
    long long minout = max(out - (right - k) * R, 0LL);
    long long t = maxin - minout;
    return t * mv + solve(left, k, in, maxin) + solve(k + 1, right, minout + R, out);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> E >> R >> N;
        for (int i = 0; i < N; ++i) cin >> v[i];
        cout << "Case #" << t << ": " << solve(0, N, E, 0) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T = 1e6;
    long long N;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        map<long long, int> steps;
        queue<long long> q;
        q.push(1);
        steps[1] = 1;
        while (steps.find(N) == steps.end()) {
            long long u = q.front();
            q.pop();
            if (steps.find(u + 1) == steps.end()) {
                steps[u + 1] = steps[u] + 1;
                q.push(u + 1);
                if (u + 1 == N) {
                    break;
                }
            }
            long long rev = 0;
            long long temp = u;
            while (temp) {
                rev = rev * 10 + temp % 10;
                temp /= 10;
            }
            if (steps.find(rev) == steps.end()) {
                steps[rev] = steps[u] + 1;
                q.push(rev);
                if (rev == N) {
                    break;
                }
            }
        }
        printf("Case #%d: ", t);
        cout << steps[N] << endl;
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

long long E, R;
int N;
long long V[10000];

long long better[10000];

void compute_better() {
    for (int i = 0; i < N; i++) {
        better[i] = -1;
        for (int j = i+1; j < N; j++) {
            if (V[j] > V[i]) {
                better[i] = j;
                break;
            }
        }
        // cout << better[i] << ' ';
    }
    // cout << endl;
}

long long solve() {
    compute_better();

    long long ans = 0;
    int curr_e = E;
    for (int i = 0; i < N; i++) {
        // cout << curr_e << ' ' << ans << endl;
        if (better[i] < 0) {
            // best in the rest
            ans += curr_e * V[i];
            curr_e = 0;
        } else {
            long long reg = (better[i] - i) * R;
            if (reg > E)
                reg = E;
            long long use = curr_e - (E - reg);
            if (use < 0)
                use = 0;
            ans += use * V[i];
            curr_e -= use;
        }
        curr_e += R;
    }

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        scanf("%lld%lld%d", &E, &R, &N);
        for (int i = 0; i < N; i++)
            scanf("%lld", &V[i]);

        printf("Case #%d: %lld\n", testcase, solve());

    }
    return 0;
}

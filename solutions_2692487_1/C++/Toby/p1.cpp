#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long A, N;
vector<long long> motes;

int check(int count) {
    long long curr = A;
    int r = 0;
    for (int i = 0; i < count; i++) {
        while (curr <= motes[i]) {
            if (curr == 1)
                return 9999;
            curr += curr - 1;
            r++;
        }
        curr += motes[i];
    }
    return r;
}

int solve() {
    sort(motes.begin(), motes.end());

    int ans = 9999;
    for (int i = 0; i <= N; i++) {
        int r = check(i) + (N - i);
        ans = min(ans, r);
    }

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        motes.clear();
        scanf("%lld%lld", &A, &N);
        for (int i = 0; i < N; i++) {
            int m;
            scanf("%d", &m);
            motes.push_back(m);
        }

        printf("Case #%d: %d\n", testcase, solve());

    }
    return 0;
}

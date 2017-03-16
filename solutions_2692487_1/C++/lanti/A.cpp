// A.cpp

// observation:
// you never give up an intermediate element
// so try all prefix

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int S[105];
void solve(int tcase)
{
    int A, N; cin >> A >> N;
    for (int i = 0; i < N; ++i) cin >> S[i];
    sort(S, S+N);

    int ans = N;
    if (A == 1) goto done;

    for (int K = 1; K <= N; ++K) {  // 0..K-1 must be collected
        int curr = N-K;
        int mote = A;

        for (int i = 0; i < K; ++i) {
            while (mote <= S[i]) { mote += mote-1; curr++; }
            mote += S[i];
        }
        ans = min(ans, curr);
    }

    done:
    cout << "Case #" << tcase << ": ";
    cout << ans << endl;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) solve(t);
}

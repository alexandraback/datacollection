// Asmall.cpp

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
    for (int b = 0; b < (1<<N); ++b) {
        int mask = b;
        int curr = 0;
        for (int i = 0; i < N; ++i) if (!(mask & 1<<i)) {
            curr++;
        }
        int mote = A;
        for (int i = 0; i < N; ++i) if (mask & 1<<i) {
            while (mote <= S[i]) {
                mote += mote-1; curr++;
            }
            assert(mote > S[i]);
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

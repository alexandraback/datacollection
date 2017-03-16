#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

int A, N;
vector <int> moles;

void load() {
    scanf("%d%d", &A, &N);

    moles.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &moles[i]);
    }
    sort(moles.begin(), moles.end());
}

int solve() {
    int sol = INF;

    if (A == 1) {
        return moles.size();
    }

    for (int take_away = 0; take_away <= N; ++take_away) {
        int t = 0, mole_size = A;
        for (int i = 0; i < N - take_away; ++i) {
            while (moles[i] >= mole_size) {
                ++t;
                mole_size += mole_size - 1;
            }
            mole_size += moles[i];
        }
        sol = min(sol, t + take_away);
    }

    return sol;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tt = 1; tt <= T; ++tt) {
        load();
        printf("Case #%d: %d\n", tt, solve());
    }
    return 0;
}

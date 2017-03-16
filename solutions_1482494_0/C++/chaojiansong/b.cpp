#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Level {
    int s1;
    int s2;
};

bool operator<(const Level& l1, const Level& l2)
{
    if (l1.s2 != l2.s2) return l1.s2 < l2.s2;
    return l1.s1 > l2.s1;
}

int T, N, state[1000];
Level S[1000];

int gao()
{
    memset(state, 0, sizeof state);
    sort(S, S + N);
    int star = 0;
    int step = 0;
    for (int i = 0; i < N; ) {
        if (star >= S[i].s2) {
            if (state[i] == 0) {
                state[i] = 1;
                star += 2;
                ++step;
            }
            else if (state[i] == 2) {
                state[i] = 3;
                star += 1;
                ++step;
            }
            ++i;
        }
        else {
            bool ok = false;
            for (int j = N - 1; j >= i; --j) {
                if (state[j] == 0 && star >= S[j].s1) {
                    state[j] = 2;
                    ++star;
                    ++step;
                    ok = true;
                    break;
                }
            }
            if (!ok) return -1;
        }
    }
    return step;
}

int main(int argc, const char *argv[])
{
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> S[i].s1 >> S[i].s2;
        cout << "Case #" << cas << ": ";
        int ans = gao();
        if (ans == -1) cout << "Too Bad" << endl;
        else cout << ans << endl;
    }
    return 0;
}

#include <iostream>
#include <set>
#include <functional>

using namespace std;

void solve(int test) {
    cout << "Case #" << test << ": ";

    long long B, M; cin >> B >> M;
    int s[55][55] = {};

    long long initialM = M;

    s[1][B] = 1;
    --M;

    for (long long i=2; i<=B-1 && M; ++i) {
        s[1][i] = 1;
        --M;
    }

    for (int i=2; i<B; ++i)
        s[i][B] = 1;

    //cerr << "M: " << M << endl;
    for (long long i=3; i<=B-1 && M; ++i) {
        //cerr << "filling row " << i << endl;
        long long mx = (1LL << (i-2)) - 1;
        //cerr << "mx: " << mx << endl;

        if (M > mx) {
            for (int from=1; from<i; ++from)
                s[from][i] = 1;
            M -= mx;
        } else {
            for (int from=2; from<i; ++from) {
                if (M & (1LL << (from - 2)))
                    s[from][i] = 1;
            }

            M = 0;
        }
    }

    if (M) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;
        int ways[55] = {};
        ways[1] = 1;
        for (int i=2; i<=B; ++i) {
            for (int from=1; from<i; ++from) {
                if (s[from][i]) {
                    ways[i] += ways[from];
                }
            }
        }
        cerr << "check: " << ways[B] << endl;
        if (ways[B] != initialM)
            throw runtime_error("oh no no no");
        for (int i=1; i<=B; ++i) {
            for (int u=1; u<=B; ++u) {
                cout << s[i][u];
            }
            cout << endl;
        }
    }
}

int main() {
    int t; cin >> t;
    for (int e=1; e<=t; ++e)
        solve(e);
}

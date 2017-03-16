#include <iostream>
#include <vector>

using namespace std;

inline long long pw(long long a, long long b) {
    long long res = 1;
    for (long long i = 0; i < b; ++i)
        res *= a;
    return res;
}

int main() {
    int T, E, R, N;
    int ga, en; int spent;
    vector<int> V; int v;
    vector<int> sp; int nn;
    vector<int> p6;
    int res;

    for (int i = 0; i < 20; ++i) {
        p6.push_back(pw(6, i));
    }

    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> E >> R >> N;
        V.clear();
        for (int i = 0; i < N; ++i) {
            cin >> v;
            V.push_back(v);
        }
        res = 0;
        sp = vector<int>(N, 0);
        for (int i = 0; i < pw(6, N); ++i) {
            ga = 0; en = E;
            if (!(i&1048575)) {
                cerr << i;
            }
            nn = 0;
            ++sp[nn];
            while (sp[nn] == 6) {
                sp[nn] = 0;
                ++nn;
                ++sp[nn];
            }
            for (int j = 0; j < N; ++j) {
                spent = sp[j];
                en -= spent;
                ga += spent * V[j];
                if (en < 0) {
                    ga = -1;
                    break;
                }
                en += R;
                if (en > E) en = E;
            }
            res = max(res, ga);
        }
        cout << "Case #" << t+1 << ": " << res << endl;
    }

    return 0;
}

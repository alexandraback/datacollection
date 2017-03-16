#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPEQ(i, n) for (int i = 0; i <= (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define FOREQ(i, a, b) for (int i = (a); i <= (int)(b); ++i)

int R, N, M, K;
int prod[20], counts[20], cards[20], ans_cards[20];
double ans_prob = 0;

double e(int i, int v)
{
    if (i == 0) {
        return 0.5 * (cards[0] == v) + 0.5 * (v == 1);
    } else {
        if (v % cards[i] == 0)
            return 0.5 * e(i - 1, v / cards[i]) + 0.5 * e(i - 1, v);
        else
            return 0.5 * e(i - 1, v);
    }
}

void f(int i)
{
    if (i == N) {
        double p = 1;
        REP(k, K)
            p *= e(N - 1, prod[k]);
        if (p > ans_prob) {
            memcpy(ans_cards, cards, sizeof(cards));
            ans_prob = p;
        }
    } else {
        FOREQ(m, 2, M) {
            cards[i] = m;
            f(i + 1);
        }
    }
}

int main()
{
    int T; cin >> T;
    REP(testcase, T) {
        cout << "Case #" << testcase + 1 << ":" << endl;
        cin >> R >> N >> M >> K;

        REP(r, R) {
            REP(k, K)
                cin >> prod[k];
            ans_prob = 0;
            f(0);

            REP(i, N)
                cout << ans_cards[i];
            cout << endl;
        }
    }
}


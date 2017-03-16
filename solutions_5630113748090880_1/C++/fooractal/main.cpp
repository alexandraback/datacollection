#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <stack>
#include <map>
#include <cassert>
#include <climits>
using namespace std;

#define REP(i, x) for (int i = 0; i < (x); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()

typedef long long ll;
typedef pair<int, int> P;

int cnt[2510];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    REP (i, T) {
        fill(cnt, cnt + 2510, 0);

        int N;
        cin >> N;
        REP (j, 2 * N - 1) {
            REP (k, N) {
                int a;
                cin >> a;
                cnt[a]++;
            }
        }

        cout << "Case #" << i + 1 << ":";
        for (int j = 1; j <= 2500; j++) {
            if (cnt[j] % 2 == 1) {
                cout << " " << j;
            }
        }
        cout << endl;
    }


    return 0;
}

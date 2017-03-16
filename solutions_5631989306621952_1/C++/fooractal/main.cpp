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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    REP (i, T) {
        string S, ans = "";
        cin >> S;
        REP (j, S.size()) {
            if (ans.size() == 0 || ans[0] > S[j]) ans += S[j];
            else ans = S[j] + ans;
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }

    return 0;
}

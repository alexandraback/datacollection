#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>

bool edge[1010][1010];

using namespace std;

int N;

string A[1010][2];

bool flag[2010];

int Left, Right;

int matching[2010];

bool extendpath(int x) {
    for (int i = 0; i < Right; ++ i)
        if (edge[x][i] && flag[i]) {
            flag[i] = false;
            if (matching[i] == -1 || extendpath(matching[i])) {
                matching[i] = x;
                return true;
            }
        }
    return false;
}

int max_matching() {
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int i = 0; i < Left; ++ i) {
        memset(flag, true, sizeof(flag));
        if (extendpath(i)) ++ ans;
    }
    return ans;
}

void solve() {
    map<string, int> L;
    map<string, int> R;
    memset(edge, false, sizeof(edge));
    Left = Right = 0;

    for (int i = 0; i < N; ++ i) {
        if (L.find(A[i][0]) == L.end()) {
            L[A[i][0]] = Left;
            ++ Left;
        }
        if (R.find(A[i][1]) == R.end()) {
            R[A[i][1]] = Right;
            ++ Right;
        }
        int x = L[A[i][0]];
        int y = R[A[i][1]];
        edge[x][y] = true;
    }
    int ret = N - (Left + Right - max_matching());
    cout << ret << endl;
}

int main() {
    int T;
    int test = 1;
    for (cin >> T; T --;) {
        cin >> N;
        for (int i = 0; i < N; ++ i)
            cin >> A[i][0] >> A[i][1];
        cout << "Case #" << test ++ << ": ";
        solve();
    }
    return 0;
}

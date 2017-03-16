#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

bool sum[35];
bool used[35];
vector<int> coins;

void genPoss(int v = 0, int sm = 0) {
    if (v == coins.size()) {
        if (sm <= 30)
            sum[sm] = true;
        return;
    }
    genPoss(v + 1, sm);
    genPoss(v + 1, sm + coins[v]);
}

bool check(int V) {
    for (int i = 0; i <= V; ++i) {
        if (!sum[i])
            return false;
    }
    return true;
}

bool ok(int V) {
    memset(sum, 0, sizeof(sum));
    genPoss();
    return check(V);
}

void solve() {
    coins.clear();
    memset(used, 0, sizeof(used));

    int C, D, V;
    cin >> C >> D >> V;
    vector<int> d(D);
    int i, j, c1, c2, c3;
    for (i = 0; i < D; ++i) {
        cin >> d[i];
        used[d[i]] = true;
        coins.push_back(d[i]);
    }

    if (!used[1])
        coins.push_back(1);
    if (!used[2])
        coins.push_back(2);

    if (ok(V)) {
        cout << coins.size() - D << "\n";
        return;
    }

    for (c1 = 3; c1 <= V; ++c1) {
        if (used[c1])
            continue;
        coins.push_back(c1);
        if (ok(V)) {
            cout << coins.size() - D << "\n";
            return;
        }
        coins.pop_back();
    }

    for (c1 = 3; c1 <= V; ++c1) {
        if (used[c1])
            continue;
        coins.push_back(c1);
        used[c1] = true;
        for (c2 = 3; c2 <= V; ++c2) {
            if (used[c2])
                continue;
            coins.push_back(c2);
            used[c2] = true;
            if (ok(V)) {
                cout << coins.size() - D << "\n";
                return;
            }
            coins.pop_back();
            used[c2] = false;
        }
        coins.pop_back();
        used[c1] = false;
    }

    int tans;
    if (V > 15)
        tans = 5;
    else if (V > 7)
        tans = 4;
    else if (V > 3)
        tans = 3;
    else if (V > 1)
        tans = 2;
    else
        tans = 1;
    if (used[1] && V >= 1)
        tans--;
    if (used[2] && V >= 2)
        tans--;
    cout << tans << "\n";
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int _T, T;
    cin >> T;
    for (_T = 1; _T <= T; ++_T) {
        printf("Case #%d: ", _T);
        solve();
    }

    return 0;
}
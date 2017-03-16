#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int C, D, V;
int ds[100];

int D_new;
int ds_new[100];

bool payable(int value, int depth) {
    if (value == 0) {
        return true;
    }
    if (value < 0) {
        return false;
    }
    if (depth >= D + D_new) {
        return false;
    }

    int coin = depth < D ? ds[depth] : ds_new[depth - D];
    return payable(value - coin, depth + 1) || payable(value, depth + 1);
}

int solve() {
    D_new = 0;
    for (int i = 1; i <= V; i++) {
        if (!payable(i, 0)) {
            ds_new[D_new] = i;
            D_new++;
        }
    }
    return D_new;
}


int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> C >> D >> V;
        for (int i = 0; i < D; i++) {
            cin >> ds[i];
        }
        int ans = solve();


        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}

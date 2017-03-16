#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;


vector < int > cn;


bool can(int v) {
    int n = cn.size();
    vector < bool > mat[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        mat[i].resize(v + 1, false);
    }
    for (int i = 0; i < n + 1; ++i) {
        mat[i][0] = true;
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < v + 1; ++j) {
            mat[i][j] = mat[i - 1][j];
            if (j - cn[i - 1] >= 0) {
                mat[i][j] = (mat[i - 1][j - cn[i - 1]] || mat[i - 1][j]);
            }
        }

    }
    return mat[n][v];
}


int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int t;
    cin >> t;
    for (int q = 1; q <= t; ++q) {
        int c, d, v;
        cin >> c >> d >> v;
        cn.resize(d);
        bool one = false;
        for (int i = 0; i < d; ++i) {
            cin >> cn[i];
            if (cn[i] == 1) {
                one = true;
            }
        }
        if (!one) {
            cn.push_back(1);
        }
        //sort(cn.begin(), cn.end());
        for (int i = 2; i <= v; ++i) {
            if (can(i)) {
                continue;
            }
            cn.push_back(i);
        }
        cout << "Case #" << q << ": " << cn.size() - d << endl;
    }
    return 0;
}
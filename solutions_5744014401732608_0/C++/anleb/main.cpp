#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <math.h>
using namespace std;

    ////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool check(vector<int> &p) {
    int m = -1e9;
    int s = 0;
    for (int i = 0; i < p.size(); ++i) {
        s += p[i];
        if (p[i] > m) {
            m = p[i];

        }
    }
    if (m * 2 > s) {
        return 1;
    }
    return 0;
}

int main(){
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int l = 0; l < t; ++l) {
        cout << "Case #" << l+1 <<": ";
        long long m, b;
        cin >> b >> m;

        vector<vector<bool> > matrix(b, vector<bool>(b, 0));
        vector<int> count(b, 0);
        m -= 1;
        matrix[0][b-1] = 1;
        count[0] = 1;
        int current  = 1;
        while (m != 0 and current < b-1) {
            matrix[current][b-1] = 1;
            matrix[0][current] = 1;
            m -= 1;
            count[current]++;
            for (int i = current-1; i > 0; --i) {
                if (count[i] <= m) {
                    m -= count[i];
                    matrix[current][i] = 1;
                    count[current] += count[i];
                }
            }
            current += 1;
        }
        if (m > 0) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << "POSSIBLE\n";

        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < b; ++j) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
        //cout << '\n';
    }
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    const int prod[4][4] = 
    {{0, 1, 2, 3},
     {1, 0, 3, 2},
     {2, 3, 0, 1},
     {3, 2, 1, 0}};
     
    const int sgn[4][4] = 
    {{0, 0, 0, 0},
     {0, 1, 0, 1},
     {0, 1, 1, 0},
     {0, 0, 1, 1}};
    int l, x;
    string s;
    
    cin >> l >> x >> s;
    if (x > 11) {
        x = (x - 11) % 4 + 11;
    }
    
    vector<int> cumsgn(l * x + 1);
    vector<int> cumprod(l * x + 1);
    cumprod[0] = cumsgn[0] = 0;
    
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < l; ++j) {
            cumprod[i * l + j + 1] = prod[cumprod[i * l + j]][s[j] - 'i' + 1];
            cumsgn[i * l + j + 1] = cumsgn[i * l + j] ^ sgn[cumprod[i * l + j]][s[j] - 'i' + 1];
        }
    }
    if (cumsgn[x * l] != 1 || cumprod[x * l] != 0) {
        cout << "NO";
        return;
    }
    vector<int> i_cnt(l * x + 1);
    vector<int> k_cnt(l * x + 1);
    for (int i = 1; i < l * x + 1; ++i) {
        i_cnt[i] = i_cnt[i - 1] + (cumprod[i] == 1 && cumsgn[i] == 0);
    }
    for (int i = l * x - 1; i >= 0; --i) {
        k_cnt[i] = k_cnt[i + 1] + (cumprod[i] == 3 && cumsgn[i] == 0);
    }
    for (int i = 0; i < l * x + 1; ++i) {
        if (i_cnt[i] && k_cnt[i]) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main() {
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        printf("\n");
    }
}

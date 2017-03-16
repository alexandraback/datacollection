#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool M[10][10];
vector <string> post;
vector <int> ord;
int n;

bool check() {
    vector <int> st;
    st.push_back(ord[0]);
    int i;
    for (i = 1; i < n; ++i) {
        while (st.size() > 0 && !M[st[st.size() - 1]][ord[i]]) st.pop_back();
        if (st.size() == 0) return false;
        st.push_back(ord[i]);
    }
    return true;
}

void solve() {
    memset(M, 0, sizeof M);

    int m, i, a, b;
    scanf("%d %d", &n, &m);

    string ans = "", s;
    post.resize(n);
    for (i = 0; i < n; ++i)
        cin >> post[i];

    for (i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        M[a][b] = true;
        M[b][a] = true;
    }

    ord.resize(n);
    for (i = 0; i < n; ++i)
        ord[i] = i;

    do {
        if (check()) {
            s = "";
            for (i = 0; i < n; ++i)
                s += post[ord[i]];
            if (ans == "" || s < ans)
                ans = s;
        }
    }
    while (next_permutation(ord.begin(), ord.end()));
    cout << ans << "\n";
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
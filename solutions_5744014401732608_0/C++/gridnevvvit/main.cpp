#include <cstdio>
#include <iostream>
#include <vector>

typedef long long li;

using namespace std;

inline void solve(int test) {
    int n, m;
    cin >> n >> m;
    vector < li > d(n);
    vector < vector < int > > ans(n, vector < int > (n, 0));
    d[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        d[i] = 0;
        for(int j = i + 1; j < n; j++) {
            d[i] += d[j];
            if (i != 0)
                ans[i][j] = 1;
        }
    }
    cerr << d[0] << endl;
    printf("Case #%d: ", test);
    if  (m <= d[0]) {
        puts("POSSIBLE");
        m--;
        for(int i = 1; i < n - 1; i++)
            if ((m & d[i]) > 0)
                ans[0][i] = 1;
        ans[0][n - 1] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                printf("%d", ans[i][j]);
            puts("");
        }
    } else {
        puts("IMPOSSIBLE");
    }
}

int main() {
    int testcount;
    cin >> testcount;
    for(int test = 0; test < testcount; test++) {
        solve(test + 1);
    }   
}   

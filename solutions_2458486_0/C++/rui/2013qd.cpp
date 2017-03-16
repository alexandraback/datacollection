#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <strstream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;
int t, k, kk ,n, a[210], b[210][210], c[210], d[210];
int ans[1048580];
int ret[1048580][20];
int keys[1048580][40];
int small(int a1, int a2, int l) {
    for (int i = 0; i < l; ++i) {
        if (ret[a1][i] < ret[a2][i])
            return 1;
        if (ret[a1][i] > ret[a2][i])
            return 0;
    }
    return 0;
}
int getbits(int x) {
    int ret = 0;
    while (x) {
        x &= (x-1);
        ret++;
    }
    return ret;
}
int main() {
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        memset(b, 0 , sizeof b);
        memset(a, 0 , sizeof a);
        memset(ans, -1, sizeof ans);
        memset(keys, 0, sizeof keys);
        memset(ret, 0, sizeof ret);
        cin >> kk >> n;
        int tmp;
        k = 0;
        for (int i = 0; i < kk; ++i) {
            cin >> tmp;
            if (tmp > k)
                k = tmp;
            a[tmp-1]++;
            keys[0][tmp-1]++;
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i] >> d[i];
            if (c[i] > k)
                k = c[i];
            for (int j = 0; j < d[i]; ++j) {
                cin >> tmp;
                if (tmp > k)
                    k = tmp;
                b[i][tmp-1]++;
            }
        }
        //cout << n << " " << k << endl;
        ans[0] = 0;
        for (int i = 0; i < (1<<n); ++i) {
            if (ans[i] == -1)
                continue;
            int  l = getbits(i);
            for (int j = 0; j < n; ++j) {
                if (i&(1<<j))
                    continue;
                tmp = i^(1<<j);
                //cout << i << " " << j << " " << keys[tmp][c[j]-1] << endl;
                if (keys[i][c[j]-1] < 1)
                    continue;
                if (ans[tmp] > -1) {
                    ret[i][l] = j;
                    if (small(i, tmp, l+1)) {
                        ans[tmp] = j;
                        for (int v = 0; v < l; ++v)
                            ret[tmp][v] = ret[i][v];
                        ret[tmp][l] = j;
                    }
                } else {
                    ans[tmp] = j;
                    keys[tmp][c[j]-1] = -1;
                    for (int key = 0; key < k; ++key)
                        keys[tmp][key] += keys[i][key]+b[j][key];
                    for (int v = 0; v < l; ++v)
                        ret[tmp][v] = ret[i][v];
                    ret[tmp][l] = j;
                }
            }
        }
        cout << "Case #" << tt << ":";
        if (ans[(1<<n)-1] == -1)
            cout << " IMPOSSIBLE" << endl;
        else {
            stack<int> ss;
            int now = (1<<n)-1;
            for (int i = 0; i < n; ++i) {
                ss.push(ans[now]+1);
                now ^= 1<<ans[now];
            }
            for (int i = 0; i < n; ++i) {
                cout << " " << ss.top();
                ss.pop();
            }
            cout << endl;
        }
    }
    return 0;
}

/*
 * C.cpp
 * Copyright (C) 2016 mlckq <moon5ckq@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;
#define NN 1005

int d[NN], f[NN], pre[NN], l[NN];

int q[NN];

vector<int> build(int u) {
    vector<int> ret;
    while (u) {
        ret.push_back(u);
        u = pre[u];
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d:", i);

        int N;
        scanf("%d", &N);
        memset(d, 0, sizeof(d));
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &f[j]);
            d[f[j]] += 1;
            l[j] = 1;
        }

        {
            memset(pre, 0, sizeof(pre));
            int h = 0, t = 0;
            for (int j = 1; j <= N; ++j)
                if (d[j] == 0) {
                    q[t ++] = j;
                }
            while ( h < t ) {
                int u = q[h ++];
                d[ f[u] ] --;
                if (l[u] + 1 > l[f[u]]) {
                    l[f[u]] = l[u];
                    pre[f[u]] = u;
                }
                if (d[f[u]] == 0)
                    q[t++] = f[u];
            }
        }

        //for (int j = 1; j <= N; ++j) printf("%d, %d, %d, %d\n", j, d[j], l[j], pre[j]);

        int b = 0;
        vector<int> bn;
        vector<int> c;

        for (int j = 1; j <= N; ++j) {
            if (d[j] == 0) {
                if (l[j] > b) {
                    b = l[j];
                    bn = build(j);
                }
            } else if (f[f[j]] == j && f[j] > j) {
                vector<int> a = build(j), a2 = build(f[j]);
                for (int k = a2.size() - 1; k >= 0; --k)
                    a.insert(a.begin(), a2[k]);
                //printf("%d, ", j); for (int k = 0; k < a.size(); ++k) printf("%d ", a[k]); printf("\n");
                c.insert(c.end(), a.begin(), a.end());
            } else {
                vector<int> a;
                a.push_back(j);
                for (int k = f[j]; k != j; k = f[k])
                    a.push_back(k);
                if (a.size() > b) {
                    b = a.size();
                    bn = a;
                }
            }
        }
        if (c.size() > b) {
            b = c.size();
            bn = c;
        }

        /*for (int j = 0; j < bn.size(); ++j)
            printf(" %d", bn[j]);*/
        printf(" %d\n", b);
    }
    return 0;
}


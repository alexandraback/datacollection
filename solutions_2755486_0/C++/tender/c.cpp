/*
 * Author: tender
 * Created Time:  2013/5/12 19:02:20
 * File Name: c.cpp
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;
const double pi = acos(-1.0);
const int mid = 500;
int h[1000];
int d[10], n[10], w[10], e[10], s[10];
int d_d[10], d_p[10], d_s[10];
struct node {
    int n, w, e, h;
    node() {}
    node(int _n, int _w, int _e, int _h) :
        n(_n), w(_w), e(_e), h(_h) {}
    bool operator < (const node& a) const {
        return n > a.n;
    }
}c[105], tmp, a[105];
int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        int N;
        scanf("%d", &N);
        int k = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], 
                    &d_d[i], &d_p[i], &d_s[i]);
            w[i] *= 2; e[i] *= 2; d_p[i] *= 2;
            for (int j = 0; j < n[i]; j++) {
                c[k++] = node(d[i] + j * d_d[i], w[i] + j * d_p[i]  + mid,
                        e[i] + j * d_p[i] + mid, s[i] + j * d_s[i]);
            }
        }
        make_heap(c, c + k);
        memset(h, 0, sizeof(h));
        int ans = 0, l = 0;
        bool first = true;
        while(k > 0) {
            if (first) {
                first = false;
                pop_heap(c, c + k);
                k--;
                a[l++] = c[k];
            }
            else {
                a[0] = tmp;
                l = 1;
            }
            while(k > 0) {
                pop_heap(c, c + k);
                k--; tmp = c[k];
                if (tmp.n != a[0].n) break;
                else a[l++] = tmp;
            }
            for (int i = 0; i < l; i++)
                for (int j = a[i].w; j <= a[i].e; j++)
                    if (a[i].h > h[j]) {
                        ans++;
                        break;
                    }
            for (int i = 0; i < l; i++)
                for (int j = a[i].w; j <= a[i].e; j++)
                    h[j] = max(h[j], a[i].h);
        }
        for (int i = 0; i < l; i++)
            for (int j = tmp.w; j <= tmp.e; j++)
                if (tmp.h > h[j]) {
                    ans++;
                    break;
                }
        printf("%d\n", ans);
    }
    return 0;
}

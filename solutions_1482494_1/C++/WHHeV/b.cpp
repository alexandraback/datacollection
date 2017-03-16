/*
 * Author: WHHeV
 * Created Time:  2012/4/28 9:25:04
 * File Name: b.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int a[1010], b[1010];
int flag[1010];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, N;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            flag[i] = 0;
        }
        int c = 0, po = 0;
        bool bad = false;
        for (;;) {
            bool has = 0;
            int lv = -1, ra = -1;
            for (int i = 0; i < N; ++i) {
                if (po >= b[i] && flag[i] == 0) {
                    if (lv < 0) {
                        lv = i;
                        ra = 2;
                        has = 1;
                        break;
                    } else if (ra < 2) {
                        lv = i;
                        ra = 2;
                        has = 1;
                        break;
                    }
                } else if (po >= b[i] && flag[i] == 1) {
                    if (lv < 0) {
                        lv = i;
                        ra = 1;
                        has = 1;
                    } else if (ra <= 1) {
                        lv = i;
                        ra = 1;
                        has = 1;
                    }
                } else if (po >= a[i] && flag[i] == 0) {
                    if (lv < 0) {
                        lv = i;
                        ra = 1;
                        has = 1;
                    } else if (ra == 1 && flag[lv] == 0) {
                        if (b[i] > b[lv]) {
                            lv = i;
                            ra = 1;
                            has = 1;
                        }
                    }
                }
            }
            //printf("[%d %d]\n", lv, ra);
            if (has) {
                ++c;
                po += ra;
                if (ra == 1) {
                    if (flag[lv] == 0)
                        flag[lv] = 1;
                    else if (flag[lv] == 1)
                        flag[lv] = 2;
                } else if (ra == 2) {
                    flag[lv] = 2;
                }
            } else {
                bool k = 1;
                for (int i = 0; i < N; ++i) {
                    if (flag[i] != 2) {
                        k = 0;
                        break;
                    }
                }
                if (!k)
                    bad = true;
                break;
            }
        }
        if (bad) {
            printf("Case #%d: Too Bad\n", t);
        } else {
            printf("Case #%d: %d\n", t, c);
        }
    }
    return 0;
}

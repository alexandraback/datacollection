/*
 * Author: WHHeV
 * Created Time:  2012/4/14 16:27:19
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

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, N, S, p;
    int t[110];
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d%d%d", &N, &S, &p);
        for (int i = 0; i < N; ++i)
            scanf("%d", &t[i]);
        int a = 0, b = 0;
        for (int i = 0; i < N; ++i) {
            if (t[i] >= 2) {
                if ((t[i] + 2) >= p * 3)
                    ++a;
                else if ((t[i] + 4) >= p * 3)
                    ++b;
            } else if (t[i] == 0) {
                if (p == 0)
                    ++a;
            } else if (t[i] == 1) {
                if (p == 0 || p == 1)
                    ++a;
            }
        }
        int ans = a + min(b, S);
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}


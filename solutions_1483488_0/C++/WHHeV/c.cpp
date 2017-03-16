/*
 * Author: WHHeV
 * Created Time:  2012/4/14 16:41:45
 * File Name: c.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

set<int> ss;
int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T, A, B;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d", &A, &B);
        int b = B;
        char bs[10];
        char *bs1 = bs;
        do {
            *(bs1++) = (b % 10) + '0';
            b /= 10;
        } while (b > 0);
        *bs1 = '\0';
        reverse(bs, bs1);
        int lb = strlen(bs);
        int ans = 0;
        char num[10];
        for (int n = A; n < B; ++n) {
            ss.clear();
            char *ts = num;
            int in = n;
            do {
                *(ts++) = (in % 10) + '0';
                in /= 10;
            } while (in > 0);
            *ts = '\0';
            reverse(num, ts);
            //printf("%s\n", num);
            int len = strlen(num);
            for (int i = 1; i < len; ++i) {
                bool big = false;
                bool flag = false;
                if (len < lb) flag = true;
                int p1 = 0, p2 = i;
                for (int j = 0; j < len; ++j) {
                    if (!flag) {
                        if (num[p2] > bs[j])
                            break;
                        else if (num[p2] < bs[j] || (j == len - 1 && num[p2] == bs[j])) {
                            flag = true;
                            if (big)
                                break;
                        }
                    }
                    if (!big) {
                        if (num[p2] > num[p1]) {
                            big = true;
                            if (flag)
                                break;
                        } else if (num[p2] < num[p1])
                            break;
                    }
                    ++p1; ++p2;
                    if (p2 >= len) p2 = 0;
                    
                }
                if (big && flag) {
                    //printf("[%s ", num);
                    p2 = i;
                    int m = 0;
                    for (int j = 0; j < len; ++j) {
                        //printf("%c", num[p2++]);
                        m *= 10;
                        m += (num[p2++] - '0');
                        if (p2 >= len) p2 = 0;
                    }
                    if (ss.find(m) == ss.end()) {
                        ss.insert(m);
                        ++ans;
                    }
                    //printf("]\n");
                    //printf("[%d %d]\n", n, i);
                }
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}


/*
 * Author: tender
 * Created Time:  2012/4/14 14:58:24
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
const int maxn = 2000000;
int cnt[maxn + 5];
int li[maxn + 2][6];
int t[maxn + 2][12];
void func(int n) {
    int l = 0, tmp = n;
    while(tmp) {
        t[n][l++] = tmp % 10; tmp /= 10;
    }
    for (int i = 0; i < l; i++)
        t[n][l + i] = t[n][i];
    int len = (l << 1);
    for (int i = len - 2; i >= l - 1; i--) {
        if (t[n][i] == '0') continue;
        int d = 0;
        for (int j = 0; j < l; j++)
            d = d * 10 + t[n][i - j];
        if (d <= n || d > maxn) continue;
        li[n][cnt[n]++] = d;
    }
}
int main() {
    //freopen("C-large.in",  "r", stdin);
    //freopen("2.txt", "w", stdout);
    for (int i = 10; i <= maxn; i++) {
        func(i);
    }
    for (int i = 0; i <= maxn; i++) {
        sort(li[i], li[i] + cnt[i]);
        if (cnt[i] > 0) {
            int tl = 1;
            for (int j = 1; j < cnt[i]; j++)
                if (li[i][j] != li[i][j - 1])
                    li[i][tl++] = li[i][j];
            cnt[i] = tl++;
        }
    }
    //int res = 0;
    //for (int i = 1111; i <= 2222; i++) {
        //printf("i = %d: ", i);
        //for (int j = 0; j < cnt[i]; j++)
            //if (li[i][j] > 2222) break;
            //else {
                //res++;
                //printf("%d ", li[i][j]);
            //}
        //printf("\n");
    //}
    //printf("res = %d\n", res);
    int cas;
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        int a, b;
        scanf("%d%d", &a, &b);
        int ans = 0;
        for (int i = a; i <= b; i++)
            for (int j = 0; j < cnt[i]; j++) {
                if (li[i][j] > b) break;
                ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}

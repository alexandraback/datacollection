//
//  main.cpp
//  B
//
//  Created by IwfWcf on 13-4-27.
//  Copyright (c) 2013年 IwfWcf. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#define lowbit(i) (i & (-i))
#define X first
#define Y second
#define N 10010

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int a[N], c[N], f[N];
PII b[N];

inline void tree_add(int idx, int num, int n)
{ //对a[idx]+=num, 改变包含a[idx]的c元素的值
    while (idx <= n) {
        c[idx] += num;
        idx += lowbit(idx);
    }
}

inline int tree_sum(int idx)
{ //计算a[1]+...+a[idx]
    int sum = 0;
    while (idx >= 1) {
        sum += c[idx];
        idx -= lowbit(idx);
    }
    return sum;
}

inline int bs(int x, int n)
{
    int now = tree_sum(x), left = x + 1, right = n;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (tree_sum(mid) == now) left = mid + 1;
        else right = mid - 1;
    }
    if (right == n) right++;
    return right;
}

int main(int argc, const char * argv[])
{
    freopen("/Users/IwfWcf/Desktop/B/input.txt", "r", stdin);
    freopen("/Users/IwfWcf/Desktop/B/output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        int e, r, n;
        scanf("%d%d%d", &e, &r, &n);
        if (r > e) r = e;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i].X = a[i], b[i].Y = i;
            c[i] = 0;
        }
        sort(b + 1, b + n + 1);
        for (int i = n; i; i--) {
            f[b[i].Y] = bs(b[i].Y, n);
            tree_add(b[i].Y, 1, n);
        }
        LL ans = 0;
        int now = e;
        for (int i = 1; i <= n; i++) {
            if (f[i] > n) {
                ans += (LL)now * a[i];
                now = 0;
            } else {
                LL temp = now + (LL)(f[i] - i + 1) * r;
                if (temp > e) {
                    temp -= e;
                    if (temp > now) temp = now;
                    ans += temp * a[i];
                    now -= temp;
                }
            }
            now += r;
        }
        cout << "Case #" << cases << ": " << ans << "\n";
    }
    return 0;
}


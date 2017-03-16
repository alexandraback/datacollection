#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int top[1010];
int nexte[1010];
int point[1010];
int totale = 0;
int mark[1010];
int a[1010];

void addedge(int x, int y) {
    totale++;
    nexte[totale] = top[x];
    point[totale] = y;
    top[x] = totale;
}

void findmaxlink(int i, int len) {
    mark[i] = len;
    if (mark[a[i]] == 0) {
        findmaxlink(a[i], len+1);
    }
}

int reversemaxlink(int i) {
    int j = top[i];
    int s = mark[i];
    while (j != 0) {
        int k = point[j];
        if (mark[k] == 0) {
            mark[k] = mark[i] + 1;
            int l = reversemaxlink(k);
            if (l > s) {
                s = l;
            }
        }
        j = nexte[j];
    }
    return s;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcase;
    scanf("%d", &testcase);
    for (int tt = 1; tt <= testcase; tt++) {
        int n;
        int ans = 0;
        scanf("%d", &n);
        totale = 0;
        for (int i = 1; i <= 1000; i++) {
            top[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            addedge(a[i], i);
        }
        ans = 0;
        int ansl = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mark[j] = 0;
            }
            if (a[i] > i && a[a[i]] == i) {
                mark[a[i]] = 1; mark[i] = 1;
                int l1 = reversemaxlink(i); // need exclude the point in 2-length-circle
                int l2 = reversemaxlink(a[i]); // need exclude the point in 2-length-circle
                if (l1 + l2 > ans) {
                    ans = l1 + l2;
                }
                ansl += l1 + l2;
            } else {
                findmaxlink(a[i], 1);
                if (mark[i] > ans) {
                    ans = mark[i];
                }
            }
        }
        if (ansl > ans) {
            ans = ansl;
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
/*
 * Author: tender
 * Created Time:  2012/5/6 0:09:33
 * File Name: a.cpp
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
const int maxn = 200;
const double eps = 1e-6;
int s[maxn + 5];
double res[maxn + 5];
int sgn(const double &t) {
    return t > eps ? 1 : (t < -eps ? -1 : 0);
}
int main() {
    int cas, n;
    freopen("al1.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d:", ii);
        int n, left;
        double sum = 0;
        scanf("%d", &n);
        left = n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        double tot = sum;
        sum *= 2;
        for (int i = 0; i < n; i++) res[i] = -1;
        while(left > 0) {
            bool flag = false;
            double tt = sum / left;
            for (int i = 0; i < n; i++) 
                if (res[i] == -1) {
                double p = (tt - s[i]) / tot;
                if (sgn(p) <= 0) {
                    res[i] = 0;
                    left--;
                    flag = true;
                    sum -= s[i];
                }
            }
            if (flag == false) break;
        }
        if (left > 0) {
            double tt = sum / left;
            for (int i = 0; i < n; i++) 
                if (res[i] == -1) {
                    res[i] = (tt - s[i]) / tot;
            }
        }
        for (int i = 0; i < n; i++)
            printf(" %.6lf", res[i] * 100);
        printf("\n");
    }
    return 0;
}

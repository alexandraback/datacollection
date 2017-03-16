/*
 * Author: tender
 * Created Time:  2013/5/12 17:33:57
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
char str[105];
char temp[] = "aeiou";
bool is[105];
bool check(const int& s, const int& e, const int& n) {
    memset(is, true, sizeof(is));
    for (int i = s; i <= e; i++)
        for (int j = 0; temp[j]; j++)
            if (str[i] == temp[j]) {
                is[i] = false;
                break;
            }
    int cnt = 0, i = s;
    while(i <= e) {
        while(i <= e && is[i]) {
            cnt++;
            i++;
        }
        if (i > e || cnt >= n) return cnt >= n;
        cnt = 0;
        while(i <= e && is[i] == false) i++;
    }
    return false;
}
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        int n;
        printf("Case #%d: ", ii);
        scanf("%s%d", str, &n);
        int ans = 0, len = strlen(str);
        for (int i = 0; i < len; i++)
            for (int j = i + n - 1; j < len; j++)
                if (check(i, j, n)) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

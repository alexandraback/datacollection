/*
 * Author: tender
 * Created Time:  2013/5/12 18:06:11
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
const int maxn = 1000000;
char s[maxn + 5];
char temp[] = "aeiou";
pair<int, int> a[maxn + 5];
bool check(const int& idx) {
    for (int i = 0; temp[i]; i++)
        if (s[idx] == temp[i]) return false;
    return true;
}
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("3.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        int n;
        scanf("%s%d", s, &n);
        int k = 0, len = strlen(s);
        int i = 0;
        if (check(i) == false) {
            int cnt = 0;
            while(i < len && check(i) == false) {
                cnt++;
                i++;
            }
            a[k++] = make_pair(0, cnt);
        }
        while(i < len) {
            int cnt1 = 0, cnt2 = 0;
            while(i < len && check(i)) {
                cnt1++;
                i++;
            }
            while(i < len && check(i) == false) {
                cnt2++;
                i++;
            }
            a[k++] = make_pair(cnt1, cnt2);
        }
        //for (int i = 0; i < k; i++)
            //printf("%d %d\n", a[i].first, a[i].second);
        long long ans = 0, l = len;
        ans = (l - n + 2) * (l - n + 1) / 2;
        i = 0;
        long long tl = 0;
        while(i < k) {
            if (a[i].first >= n) {
                tl += n - 1;
                ans -= (tl - n + 2) * (tl - n + 1) / 2;
                tl = n - 1 + a[i].second;
                i++;
                continue;
            }
            tl += a[i].first + a[i].second;
            i++;
        }
        if (tl >= n) ans -= (tl - n + 2) * (tl - n + 1) / 2;
        //else if (k > 1 && a[k - 1].first >= n) {`
            //tl = n - 1 + a[k - 1].second;
            //ans -= (tl - n + 2) * (tl - n + 1) / 2;
        //}
        printf("%lld\n", ans);
    }
    return 0;
}

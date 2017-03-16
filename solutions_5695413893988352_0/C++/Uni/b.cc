#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

char c[100], j[100];

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", c, j);
        int len = strlen(c);
        int flag = 0;
        for (int i = 0; i < len; ++i) {
            if (c[i] == '?' && c[i] == j[i]) {
                if (flag == 0) {
                    c[i] = j[i] = '0';
                } else if (flag > 0) {
                    c[i] = '0';
                    j[i] = '9';
                } else {
                    c[i] = '9';
                    j[i] = '0';
                }
            } else if (c[i] == '?') {
                if (flag == 0) {
                    c[i] = j[i];
                } else if (flag > 0) {
                    c[i] = '0';
                } else {
                    c[i] = '9';
                }
            } else if (j[i] == '?') {
                if (flag == 0) {
                    j[i] = c[i];
                } else if (flag > 0) {
                    j[i] = '9';
                } else {
                    j[i] = '0';
                }
            } else {
                if (flag == 0) {
                    if (c[i] > j[i]) {
                        flag = 1;
                    } else if (c[i] < j[i]) {
                        flag = -1;
                    }
                }
            }
        }
        printf("Case #%d: %s %s\n", ++cas, c, j);
    }
    return 0;
}
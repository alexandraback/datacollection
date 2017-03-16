#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

int p[2000005];
int t[2000005];

int main() {
    for (int num = 1; num <= 2000000; ++num) {
        string str = "";
        int x = num;
        while (x > 0) {
            str = string(1, (x % 10) + '0') + str;
            x = x / 10;
        }
        string best = str;
        str = str + str;
        for (int i = 0; i < str.size() / 2; ++i) {
            if (str[i] == '0') continue;
            string tmp = "";
            for (int j = 0; j < str.size() / 2; ++j)
                tmp += str[i + j];
            if (tmp < best) best = tmp;
        }
        int t = 0;
        for (int i = 0; i < best.size(); ++i)
            t = t * 10 + best[i] - '0';
        p[num] = t;
    }
    int tests; scanf("%d", &tests);
    for (int testId = 1; testId <= tests; ++testId) {
        int a, b;
        scanf("%d%d", &a, &b);
        memset(t, 0, sizeof(t));
        int res = 0;
        for (int i = a; i <= b; ++i) {
            res += t[p[i]];
            t[p[i]]++;
        }
        printf("Case #%d: %d\n", testId, res);
    }
    return 0;
}

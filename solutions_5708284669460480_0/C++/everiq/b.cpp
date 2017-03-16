#include <bits/stdc++.h>
using namespace std;

int k, l, s;
char a[100], b[100];
int max_bananas;
long long int total = 0;
long long int total_count = 0;

char t[100];

void find(int idx) {
    if (idx == s) {
        int cnt = 0;
        for (int i = 0; i < s - l+1; ++i)
            if (0 == memcmp(b, t+i, l)) ++cnt;
        max_bananas = max(cnt, max_bananas);
        total++;
        total_count += cnt;
        return;
    }

    for (int i = 0; i < k; ++i) {
        t[idx] = a[i];
        find(idx+1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int qq = 1; qq <= t; ++qq) {
        scanf("%d %d %d\n", &k, &l, &s);
        scanf("%s\n", a);
        scanf("%s\n", b);
        max_bananas = 0;
        total = total_count = 0;
        find(0);

        printf("Case #%d: %0.12lf\n", qq, max_bananas ? (double) max_bananas - (double) total_count / total : 0.0);
    }
    return 0;
}

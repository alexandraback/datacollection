#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>

using namespace std;

struct entry {
    int fst, snd;
    bool inc, end;
} element[1005];

int cmp(const void *p, const void *q) {
    entry *a = (entry *) p;
    entry *b = (entry *) q;
    return b->snd - a->snd;
}

int main() {
    freopen("D:\\B-small-attempt0.in", "r", stdin);
    freopen("D:\\B-small-attempt0.out", "w", stdout);
    int t, tt = 0, n, i, star, cnt, old, num;
    scanf("%d", &t);
    while (t--) {
        num = 0;
        cnt = 0;
        star = 0;
        old = 0;
        tt++;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d%d", &element[i].fst, &element[i].snd);
            element[i].inc = element[i].end = 0;
        }
        qsort(element, n, sizeof (element[0]), cmp);
        while (cnt < n) {
            for (i = 0; i < n; i++) {
                if (element[i].snd <= star && !element[i].end) {
                    if (element[i].inc)star++;
                    else star += 2;
                    element[i].inc = 1;
                    element[i].end = 1;
                    cnt++;
                    num++;
                }
            }
            if (old == star) {
                for (i = 0; i < n; i++)
                    if (element[i].fst <= star && !element[i].inc && !element[i].end) {
                        star++;
                        element[i].inc = 1;
                        num++;
                        break;
                    }
                if (i == n) {
                    printf("Case #%d: Too Bad\n", tt);
                    goto output;
                }
            }
            old = star;
        }
        printf("Case #%d: %d\n", tt, num);
output:
        ;
    }
    return 0;
}

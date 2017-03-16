#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int sz = 0;
unsigned db[10000];

bool test(long i) {
    char buf[200];
    sprintf(buf, "%ld", i);
    int l = strlen(buf);
    for (int j = l / 2; j >= 0; j--)
        if (buf[j] != buf[l - j - 1])
            return false;
    return true;
}

void init() {
    for (int i = 1; i <= 10000000; i++) {
        if (test(i) && test((long)i * i)) {
            db[sz++] = i;
            //printf("%d\n", i);
        }
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        long l, r;
        int ll, rr;
        scanf("%ld%ld", &l, &r);
        l = ceil(sqrt(l));
        r = ceil(sqrt(r + 0.5));
        ll = lower_bound(db, db + sz, l) - db;
        rr = lower_bound(db, db + sz, r) - db;
        printf("Case #%d: %d\n", t, rr - ll);
    }
}

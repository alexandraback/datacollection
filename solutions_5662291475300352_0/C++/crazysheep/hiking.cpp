#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);

        long long fd;
        double fs = 0;
        long long sd;
        double ss = 0;
        for (int i = 0; i < n; ++i) {
            int d, h, m;
            scanf("%d %d %d", &d, &h, &m);

            if (h == 2) {
                fd = d;
                fs = 360.0 / m;
                sd = d;
                ss = 360.0 / (m + 1);
            } else {
                if (360.0 / m > fs) {
                    if (fs != 0) {
                        sd = fd;
                        ss = fs;
                    }
                    fd = d;
                    fs = 360.0 / m;
                } else {
                    sd = d;
                    ss = 360.0 / m;
                }
            }
        }
        // printf("fd fs %lld %lf sd ss %lld %lf\n", fd, fs, sd, ss);

        if (ss == 0) {
            printf("Case #%d: 0\n", t);
        }

        bool canSecond = fd < sd;
        double ds = fs - ss;
        if (ds == 0) {
            printf("Case #%d: 0\n", t);
            continue;
        }
        long long dd = (sd - fd + 360) % 360;
        if (dd == 0) {
            canSecond = true;
        }
        double times = dd / ds;

        double traveled = ss * times;
        if (sd + traveled >= 360) {
            printf("Case #%d: 0\n", t);
            continue;
        } else if (canSecond) {
            // second revolution chance
            sd += traveled;
            times = 360 / ds;
            traveled = ss * times;
            if (sd + traveled >= 360) {
                printf("Case #%d: 0\n", t);
                continue;
            }
        }
        printf("Case #%d: 1\n", t);
    }
}
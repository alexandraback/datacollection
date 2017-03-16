#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

int m[64];

namespace abc {
    int a, b, c;
    void abc() {
        if (a <= 10 && b <= 10 && c <= 10) {
            int surprise = (c - a == 2 || b - a == 2 || c - b == 2);
            m[(a+b+c) * 2 + surprise] = c;
        }
    }

    void test() {
        memset(m, -1, sizeof(m));
        for (int i = 0; i <= 10; ++i) {
            // 0 0 0
            // 0 0 1
            // 0 0 2 S
            // 0 1 1
            // 0 1 2 S
            // 0 2 2 S
            a = b = c = i;
            abc();
            c++;
            abc();
            c++;
            abc();
            b++;
            c--;
            abc();
            c++;
            abc();
            b++;
            abc();
        }
    }
}

int T, n, s, p, t[128];

namespace dp {
    int fc[128][128];

    void init() { 
        memset(fc, -1, sizeof(fc)); 
        memset(fc[0], 0x80, sizeof(fc[0])); 
        fc[0][0] = 0;
    }

    int f(int n, int s) {
        if (fc[n][s] == -1) {
            int total_score = t[n];
            int best_r = -2147483647;
            if (s && m[total_score * 2 + 1] >= 0) {
                int r = f(n - 1, s - 1) + (m[total_score * 2 + 1] >= p);
                if (r > best_r) best_r = r;
            }
            if (m[total_score * 2] >= 0) {
                int r = f(n - 1, s) + (m[total_score * 2] >= p);
                if (r > best_r) best_r = r;
            }
            fc[n][s] = best_r;
        }
        return fc[n][s];
    }
}


int main(int argc, char const *argv[]) {
    abc::test();
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d%d%d", &n, &s, &p);
        for (int j = 1; j <= n; ++j) scanf("%d", t + j);
        dp::init();
        printf("Case #%d: %d\n", i, dp::f(n, s));
    }
    return 0;
}

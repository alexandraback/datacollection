#include <cstdio>
#include <cstdlib>

int jp[150];
int js[150];
int sp[150];

int results[1005][3];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int j, p, s, k;
        scanf("%d %d %d %d", &j, &p, &s, &k);

        int total = 0;
        for (int i = 0; i < 150; ++i) {
            jp[i] = 0;
            js[i] = 0;
            sp[i] = 0;
        }

        for (int a = 0; a < j; ++a) {
            for (int b = 0; b < p; ++b) {
                for (int c = 0; c < s; ++c) {
                    bool ok = true;
                    for (int i = 0; i < total; ++i) {
                        if (jp[a*11 + b] >= k) {
                            ok = false;
                            break;
                        }
                        if (js[a*11 + c] >= k) {
                            ok = false;
                            break;
                        }
                        if (sp[b*11 + c] >= k) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    results[total][0] = a + 1;
                    results[total][1] = b + 1;
                    results[total][2] = c + 1;
                    total++;

                    jp[a*11 + b]++;
                    js[a*11 + c]++;
                    sp[b*11 + c]++;
                }
            }
        }

        printf("Case #%d: %d\n", cs, total);
        for (int i = 0; i < total; ++i) {
            printf("%d %d %d\n", results[i][0], results[i][1], results[i][2]);
        }
    }
}



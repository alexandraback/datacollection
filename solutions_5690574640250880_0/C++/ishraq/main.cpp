#include <cstdio>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    FO(Z,0,T) {
        printf("Case #%d:\n", Z+1);

        int m, h, w;
        scanf("%d %d %d", &h, &w, &m);
        m = h*w-m;

        if (h == 1 || w == 1 || m == 1) {
            int rem = m;
            FO(y,0,h) {
                FO(x,0,w) {
                    if (rem) {
                        if (rem == m) printf("c");
                        else printf(".");
                        rem--;
                    } else printf("*");
                }
                printf("\n");
            }
            goto done;
        } else {
            FO(bw,2,w+1) {
                FO(bh,2,h+1) {
                    int left = m-bw*bh;
                    if (left < 0 || left == 1) continue;
                    if (bw*bh == 4 && left == 3) continue;

                    int cpb = (bh != h) * bw;
                    int cpr = (bw != w) * bh;

                    if (left > cpb+cpr) continue;

                    int becareful = cpr+1 == left;

                    FO(y,0,h) {
                        FO(x,0,w) {
                            if (y == 0 && x == 0) printf("c");
                            else if (y < bh && x < bw) printf(".");
                            else if (y == bh) {
                                if (left) {
                                    printf(".");
                                    left--;
                                } else printf("*");
                            } else if (x == bw) {
                                if (left && (!becareful || y+1 != bh)) {
                                    printf(".");
                                    left--;
                                } else  printf("*");
                            } else printf("*");
                        }
                        printf("\n");
                    }
                    goto done;
                }
            }
        }

        printf("Impossible\n");
done:;
    }

    return 0;
}


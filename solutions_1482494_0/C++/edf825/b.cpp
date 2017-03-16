#include <stdio.h>
#include <algorithm>

using namespace std;

struct Level {
    int a, b;
    bool adone, bdone;
};

bool operator<(const Level& a, const Level& b)
{
    if (a.bdone == b.bdone) {
        if (a.b == b.b) {
            if (a.adone == b.bdone) {
                return b.a < a.a;
            }
            return b.adone;
        }
        return a.b < b.b;
    }
    return b.bdone;
}

int main()
{
    int T;
    scanf("%d", &T);

    Level l[2048];

    for (int K = 1; K <= T; K++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            l[i] = (Level){a, b, false, false};
        }

        bool bad = false;

        int stars = 0;
        int turns = 0;
        int numl = n;
        while (numl) {
            sort(l, l + n);
            bool bfound = false;
            int bmax = -1;
            int amin = stars;
            int adx = -1;
            for (int j = 0; j < numl; j++) {
                if (l[j].b <= stars) {
                    //printf("+");
                    stars += l[j].adone ? 1 : 2;
                    l[j].bdone = l[j].adone = true;
                    numl--;
                    bfound = true;
                    break;
                } else if (l[j].a <= stars && l[j].b > bmax && !l[j].adone) {
                    //printf("-");
                    bmax = l[j].b;
                    adx = j;
                }
                //printf("stars = %d, b = %d\n", stars, l[j].b);
            }

            if (!bfound && adx > -1) {
                l[adx].adone = true;
                stars++;
            } else if (!bfound && adx == -1) {
                bad = true;
                break;
            }

            turns++;
        }

        printf("Case #%d: ", K);
        if (bad) {
            printf("Too Bad\n");
        } else {
            printf("%d\n", turns);
        }
    }

    return 0;
}

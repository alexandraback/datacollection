#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define NMAX 2048

struct f {
    int i;
    int first, second;
    bool operator < (const f &g) const {
        if (first == g.first)
            return second > g.second;
        return first < g.first;
    }
} F[NMAX];

struct s {
    int i;
    int second;
    bool operator < (const s &g) const {
        return second < g.second;
    }
} S[NMAX];

int n;
int star[NMAX];

int main() {
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &F[i].first, &F[i].second);
            S[i].second = F[i].second;
            F[i].i = S[i].i = i;
            star[i] = 2;
        }
        sort(F, F+n);
        sort(S, S+n);

        int pf = 0, ps = 0;
        int output = 0, stars = 0;
        while (ps < n) {
            // get second star
            if (stars >= S[ps].second) {
                assert(star[S[ps].i] != 0);
                stars+= star[S[ps].i];
                star[S[ps].i] = 0;
                output++;
                ps++;
                continue;
            }
            
            // get first star
            while (pf < n && star[F[pf].i] == 0) {
                pf++;
            }

            int i = pf;
            while (i < n && stars >= F[i].first) {
                F[i++].first = stars;
            }
            sort(F+pf, F+n);

            if (pf < n && stars >= F[pf].first) {
                assert(star[F[pf].i] == 2);
                stars++;
                star[F[pf].i]--;
                output++;
                pf++;
                continue;
            }

            // got nothing
            output = -1;
            break;
        }

        printf("Case #%d: ", test);
        if (output == -1) {
            printf("Too Bad");
        } else {
            printf("%d", output);
        }
        printf("\n");
    }
    return 0;
}


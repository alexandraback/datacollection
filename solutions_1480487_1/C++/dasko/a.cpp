#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

LD c[210], S, EPS = 1e-14; int n;

int check(LD M, int k) {
    LD z = c[k] + M * S, p = 0.0;
    REP (i, n) {
        if (i != k) {
            if (c[i] - z < -EPS)
                p += (z - c[i]) / S;
        }
    }
    return p - (1.0 - M) >= -EPS;
}
    
int main(void) {
    int T; scanf("%d", &T);
    FOR (t, 1, T + 1) {
        scanf("%d", &n); S = 0.0;
        REP (i, n) {
            scanf("%Lf", &c[i]);
            S += c[i];
        }
        printf("Case #%d:", t);
        REP (i, n) {
            LD l = 0.0, r = 1.0;
            REP (w, 300) {
                LD mid = (l + r) * 0.5;
                if (check(mid, i))
                    r = mid;
                else
                    l = mid;
            }
            printf(" %.10Lf", l * 100.0);
        }
        puts("");
        fprintf(stderr, "%d\n", t);
    }
    return 0;
}



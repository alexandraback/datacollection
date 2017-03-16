#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <vector>

using namespace std;

#define D if (0)

#define N 3
#define M 5
#define K 7

int r, n, m, k;

typedef int v20[20];

int ds[20][3];
v20 vs[78126]; // M ** K
// int ps[2187][7]; // N ** K


void v20add(v20& a, const v20& b) { for (int i = 0; i < 20; ++i) { if (b[i] == -1 || a[i] == -1) a[i] = -1; else a[i] += b[i]; } }
int v20maxi(const v20& x) { int r = 0, m = x[0]; for (int i = 0; i < 20; ++i) { if (x[i] > m) { m = x[i]; r = i; } } return r; }

void init_ds() {
    int c = -1;
    for (int d1 = 2; d1 <= 5; ++d1)
    for (int d2 = d1; d2 <= 5; ++d2)
    for (int d3 = d2; d3 <= 5; ++d3) {
        c++;
        ds[c][0] = d1;
        ds[c][1] = d2;
        ds[c][2] = d3;
    } // 20
}

// void init_ps() {
//     int c = -1;
//     int pc[7];
// #define F(i) for (pc[i] = 0; pc[i] <= 3; ++pc[i])
//     F(0) F(1) F(2) F(3) F(4) F(5) F(6) {
// #undef F
//         c++;
//         memcpy(ps[c], pc, sizeof(pc));
//     }
// }

void init_vs() {
    memset(vs, -1, sizeof(vs));
    memset(vs[1], 0, sizeof(vs[1]));

    for (int di = 0; di < (int)(sizeof(ds) / sizeof(ds[0])); ++di) {
        // ignore 1
        const int * d = ds[di];
        int pp[3];

        D printf("di = %d [ %d %d %d ]\n", di, d[0], d[1], d[2]);

        for (pp[0] = 0; pp[0] <= 1; ++pp[0])
        for (pp[1] = 0; pp[1] <= 1; ++pp[1])
        for (pp[2] = 0; pp[2] <= 1; ++pp[2]) {
            int p = 1;
            for (int i = 0; i < 3; ++i) if (pp[i]) p *= d[i];
            if (p == 1) continue;
            D printf("  p = %d\n", p);
            if (vs[p][di] == -1) vs[p][di] = 1;
            else vs[p][di]++;
        }
    }
}



int main(int argc, char const *argv[]) {
    init_ds();
    // init_ps();
    init_vs();

    int tc;
    scanf("%d", &tc);

    for (int ti = 1; ti <= tc; ++ti) {
        printf("Case #%d:\n", ti);
        scanf("%d%d%d%d", &r, &n, &m, &k);
        for (int i = 0; i < r; ++i) {
            v20 vr;
            memset(vr, 0, sizeof(vr));

            for (int j = 0; j < k; ++j) {
                int p;
                scanf("%d", &p);
                v20add(vr, vs[p]);
                D {
                    printf("vs[%02d]: ", p);
                    for (int i = 0; i < 20; ++i) {
                        printf("%2d ", vs[p][i]);
                    }
                    printf("\n");
                    printf("vr    : ");
                    for (int i = 0; i < 20; ++i) {
                        printf("%2d ", vr[i]);
                    }
                    printf("\n");
                }
            }

            int di = v20maxi(vr);
            printf("%d%d%d\n", ds[di][0], ds[di][1], ds[di][2]);
        }
    }

    return 0;
}

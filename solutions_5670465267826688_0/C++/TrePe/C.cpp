#include <stdio.h>

int N, kejs, L, X, i, j;
char a[10005], aa[10005];
char cache[10005][10005];

short t[8][8] = {
    {0,1,2,3,4,5,6,7},
    {1,4,3,6,5,0,7,2},
    {2,7,4,1,6,3,0,5},
    {3,2,5,4,7,6,1,0},
    {4,5,6,7,0,1,2,3},
    {5,0,7,2,1,4,3,6},
    {6,3,0,5,2,7,4,1},
    {7,6,1,0,3,2,5,4}
};

bool is(int from, int to, int what) {
    int res = cache[from][to-1];
    /*
    for (i = from; i < to; i++) {
        res = t[res][aa[i] - 0];
    }
    */
    return res == what;
}

bool isi(int from, int to) {
    return is(from, to, 1);
}

bool isj(int from, int to) {
    return is(from, to, 2);
}

bool isk(int from, int to) {
    return is(from, to, 3);
}

int main() {
    scanf("%d", &N);
    for (kejs = 1; kejs <= N; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%d%d%s", &L, &X, a);
        for (i = 0; i < X; i++) {
            for (j = 0; a[j]; j++) {
                aa[L*i + j] = a[j] - 'i' + 1;
            }
        }
        L = L * X;
        for (i = 0; i < L; i++) {
            cache[i][i] = aa[i] - 0;
            for (j = i+1; j < L; j++) {
                cache[i][j] = t[cache[i][j-1] - 0][aa[j] - 0];
            }
        }
        for (i = 1; i < L - 1; i++) {
            if (!isi(0, i)) continue;
            for (j = i + 1; j < L; j++) {
                if (!isj(i, j)) continue;
                if (isk(j, L)) goto done;
            }
        }
        done:
        if (j < L) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct type {
    int s;
    int ind;
};
type soma[2000000];
bool comp (type a, type b) {
    return a.s < b.s;
}
int v[100];
int n;
int main () {
    int t;
    scanf("%d", &t);
    for (int lo = 1; lo <= t; lo++) {
        scanf("%d", &n);
        printf("Case #%d:\n", lo);
        for (int c = 0; c < n; c++) {
            scanf("%d", &v[c]);
        }
        for (int c = 1; c < (1<<n); c++) {
            soma[c].ind = c;
            soma[c].s = 0;
            for (int b = 0; b < n; b++) {
                if (c & (1<<b)) {
                    soma[c].s += v[b];
                }
            }
        }
        bool aux = false;
        sort(&soma[1], &soma[(1<<n)], comp);
        for (int c = 2; c < (1<<n); c++) {
            if(soma[c].s == soma[c-1].s) {
                for (int b = 0; b < n; b++) {
                    if (soma[c].ind & (1<<b)) {
                        printf("%d ", v[b]);
                    }
                }
                printf("\n");
                for (int b = 0; b < n; b++) {
                    if (soma[c-1].ind & (1<<b)) {
                        printf("%d ", v[b]);
                    }
                }
                printf("\n");
                aux = true;
                break;
            }
        }
        if (!aux) printf("Impossible\n");
    }
    return 0;
}

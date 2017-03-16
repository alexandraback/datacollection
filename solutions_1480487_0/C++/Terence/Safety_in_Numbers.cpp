#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

#define N 100000

int n, sx;

struct vote {
    int id;
    int s;
    double p;
} v[N];

int comp_id(const void *a, const void *b)
{
    return ((vote *)a)->id - ((vote *)b)->id;
}
int comp_sc(const void *a, const void *b)
{
    return ((vote *)a)->s - ((vote *)b)->s;
}

int main()
{
    int t;
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    freopen("a-small-attempt0.in", "r", stdin);
    freopen("a-small-attempt0.out", "w", stdout);
    //freopen("a-large.in", "r", stdin);
    //freopen("a-large.out", "w", stdout);
    scanf("%d", &t);
    for(int idx = 1; idx <= t; idx++) {
        scanf("%d", &n);
        sx = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i].s);
            sx += v[i].s;
            v[i].p = 0.0; v[i].id = i;
        }
        
        qsort(v, n, sizeof(vote), comp_sc);
        int sv = sx, i = 1;
        while(i < n && i * (v[i].s - v[i-1].s) <= sv) {
            sv -= i * (v[i].s - v[i-1].s);
            ++i;
        }
        double sf = (double)v[i-1].s + (double)sv / (double)i;
        for(int j = 0; j < i; j++) {
            v[j].p = (sf - (double)v[j].s)/sx;
        }
        
        qsort(v, n, sizeof(vote), comp_id);
        printf("Case #%d:", idx);
        for(int i = 0; i < n; i++)
            printf(" %.6lf", 100.0*v[i].p);
        printf("\n");
    }
    return 0;
}

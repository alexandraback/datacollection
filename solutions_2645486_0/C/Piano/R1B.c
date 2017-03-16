#include<stdio.h>
#include<stdlib.h>

#define MAX(x,y) ((x)>(y)?(x):(y))

struct act{
    int value, order;
};

int cmp(const void *a, const void *b){
    struct act *x = (struct act*)a, *y = (struct act*)b;
    if (x->value < y->value)return 1;
    if (x->value > y->value)return -1;
    if (x->order > y->order)return 1;
    if (x->order < y->order)return -1;
    return 0;
}

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        long long e, r, sum = 0, up[10001];
        int n, i, j, k, l;
        char vis[10000] = {};
        struct act v[10000];
        scanf("%I64d%I64d%d", &e, &r, &n);
        for (i = 0 ; i < n ; ++i)
            scanf("%d", &v[i].value), v[i].order = i, sum += v[i].value, up[i] = e;
        if (r >= e){
            printf("Case #%d: %I64d\n", u, sum * e);
            continue;
        }
        qsort(v, n, sizeof(struct act), cmp);
        l = v[0].order, sum = e * v[0].value, vis[v[0].order] = 1;
        for (j = v[0].order + 1, k = r ; j < n && k < e ; ++j, k += r)
            up[j] = k;
        up[n] = r;
        for (i = 1 ; i < n ; ++i){
            vis[v[i].order] = 1;
            if (v[i].order < l){
                if (up[v[i].order] == e)sum += r * v[i].value;
                else {
                    for (j = v[i].order + 1 ; j < n && !vis[j] ; ++j);
                    int m = MAX(0, up[j] - (j - v[i].order) * r);
                    sum += (up[v[i].order] - m) * v[i].value;
                    for (j = v[i].order + 1, k = r ; j < n && k < e && !vis[j] ; ++j, k += r)
                        up[j] = m + k;
                }
            }
            else {
                sum += up[v[i].order] * v[i].value;
                l = v[i].order;
                for (j = v[i].order + 1, k = r ; j < n && k < e && !vis[j] ; ++j, k += r)
                    up[j] = k;
            }
        }
        printf("Case #%d: %I64d\n", u, sum);
    }
}

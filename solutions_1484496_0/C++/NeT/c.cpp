#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

typedef double real;
typedef long long int64;

#define Eo(x) { cerr << #x << " = " << x << endl; }

#define maxn 20
#define maxmask (1 << maxn)

int sums[maxmask], ind[maxmask];
int s[maxn];

bool cmp(int i, int j) {
    return sums[i] < sums[j];
}

int main() {
    int t = 1, tc;
    for(scanf("%d", &tc); t <= tc; ++t) {
        printf("Case #%d:\n", t);

        int n, i, j;
        scanf("%d", &n);
        assert(n == maxn);

        for(i = 0; i < n; i++)
            scanf("%d", &s[i]);

        for(int mask = 0; mask < (1 << n); ++mask) {
            int cursum = 0;
            for(i = 0; i < n; i++)
                if(mask & (1 << i))
                    cursum += s[i];
            sums[mask] = cursum;
        }

        for(j = 0; j < (1 << n); j++) ind[j] = j;
        sort(ind, ind+j, cmp);

        for(i = 0; i < (1 << n); i = j) {
            for(j = i; j < (1 << n) && sums[ind[i]] == sums[ind[j]]; j++);

            int u, v;
            for(u = i; u < j; u++) {
                for(v = i; v < j; v++)
                    if(u != v && !(ind[u] & ind[v]))
                        break;
                if(v < j) break;
            }
            if(u < j) {
                for(j = 0; j < n; j++)
                    if(ind[u] & (1 << j))
                        printf("%d ", s[j]);
                printf("\n");
                for(j = 0; j < n; j++)
                    if(ind[v] & (1 << j))
                        printf("%d ", s[j]);
                printf("\n");
                break;
            }
        }
        if(i >= (1 << n))
            printf("Impossible\n");
    }
    return 0;
}

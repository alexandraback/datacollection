#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int table[1010][1010];
int req[1010][1010];
int mark[1010];
int aa, nn, n;

int func(int a)
{
    int i, j;
    if (mark[a] == aa) return 0;
    mark[a] = aa;
    for ( i = 0; i < n; i++ ) {
        if (table[a][i] == aa) {
            if (func(i)) return 1;
            for ( j = 0; j < n; j++ ) {
                req[a][j] += req[i][j];
                if (req[a][j] > 1) return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t, i, j, a, found;
    scanf("%d",&nn);
    memset(table,0,sizeof(table));
    memset(mark,0,sizeof(mark));
    for ( aa = 1; aa <= nn; ++aa ) {
        scanf("%d",&n);
        memset(req,0,sizeof(req));
        for ( i = 0; i < n; ++i ) {
            scanf("%d",&t);
            for ( j = 0; j < t; ++j ) {
                scanf("%d",&a);
                a--;
                table[i][a] = aa;
                req[i][a] = 1;
            }
        }
        found = 0;
        for ( i = 0; !found && i < n; ++i ) {
            found = func(i);
        }
        if (found) {
            printf("Case #%d: Yes\n",aa);
        } else {
            printf("Case #%d: No\n",aa);
        }
    }
    return 0;
}


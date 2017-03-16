#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int sizes[100];
int memo[201][100];
int n;

int doit(int size, int pos) {
    if(pos == n) return 0;

    int& ret = memo[size][pos];
    if(ret != -1) return ret;
    ret = 1 + doit(size, pos+1);

    if(size > sizes[pos])
        ret = min(ret, doit(min(size + sizes[pos], 200), pos+1));
    if(size > 1 && size <= 100)
        ret = min(ret, 1 + doit(2*size-1, pos));

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int a;
        scanf("%d %d", &a, &n);
        memset(memo, -1, sizeof memo);

        for(int i = 0; i < n; i++)
            scanf("%d", &sizes[i]);
        sort(sizes, sizes+n);

        printf("Case #%d: %d\n", z, doit(a, 0));
    }
}

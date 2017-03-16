#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

#define N 100000

int n, x[N];

void print(int m)
{
    for(int i = 0; i < n; i++)
        if(m & (1<<i)) {
            m ^= (1<<i);
            printf("%d%c", x[i], (m?' ':'\n'));
        }
}

int main()
{
    int t;
    freopen("c-small-attempt0.in", "r", stdin);
    freopen("c-small-attempt0.out", "w", stdout);
    scanf("%d", &t);
    for(int idx = 1; idx <= t; idx++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        std::map<int,int> sp;
        bool done = false;
        for(int i = 1; i < (1<<n); i++) {
            int sx = 0;
            for(int j = 0; j < n; j++)
                if(i & (1<<j))
                    sx += x[j];
            if(sp.count(sx)) {
                int y = sp[sx];
                int d = (i&y);
                if(i != d && y != d) {
                    printf("Case #%d:\n", idx);
                    print(i^d);
                    print(y^d);
                    done = true;
                    break;
                } else if(i == d) {
                    sp[sx] = i;
                }
            } else {
                sp[sx] = i;
            }
        }
        if(!done) {
            printf("Case #%d:\n", idx);
            printf("Impossible\n");
        }
    }
    return 0;
}

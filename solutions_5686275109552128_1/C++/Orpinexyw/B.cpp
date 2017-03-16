#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;


int check(int D, int p[], int goal) {
    int now = 0, ex = 0;
    for (int i = 0; i < D; i++) {
        if (p[i] > goal) {
            ex += (int)ceil((double)p[i] / goal) - 1;
        }
    }
    return ex + goal;
    // for (int i = 0; i < D; i++) {
    //     if (p[i] > goal) {
    //         ex += 
    //     }
    // }
}

int D, p[1008];

void work() 
{
    scanf("%d", &D);
    int mp = 0;
    for (int i = 0; i < D; i++) {
        scanf("%d", p + i);
        mp = max(mp, p[i]);
    }
    int ret = mp;
    for (int i = 1; i <= mp; i++) {
        ret = min(ret, check(D, p, i));
    }
    printf("%d\n", ret);
}
int main() 
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}
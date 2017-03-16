#include <cstdio>

#define SIZE    105

int main() {
    bool flag;
    unsigned tests;
    unsigned a, b, l[SIZE][SIZE], rm[SIZE], cm[SIZE];

    scanf("%u", &tests);
    for(int t = 0; t < tests; ++t) {
        scanf("%u %u", &a, &b);

        for(int x = 0; x < a; ++x)  rm[x] = 0;
        for(int y = 0; y < b; ++y)  cm[y] = 0;

        for(int x = 0; x < a; ++x) {
            for(int y = 0; y < b; ++y) {
                scanf("%u", *(l+x)+y);
                rm[x] = l[x][y] > rm[x] ? l[x][y] : rm[x];
                cm[y] = l[x][y] > cm[y] ? l[x][y] : cm[y];
            }
        }

        flag = true;
        for(int x = 0; x < a && flag; ++x)
            for(int y = 0; y < b && flag; ++y)
                flag = (l[x][y] >= rm[x] || l[x][y] >= cm[y]);

        if(flag)        printf("Case #%u: YES\n", t+1);
        else            printf("Case #%u: NO\n", t+1);
    }
    return 0;
}

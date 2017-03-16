#include <cstdio>

using namespace std;

int n, br[100];

int sum(int mask) {
    int sum = 0;
    for(int i = 0; i < 20; ++i) {
        if( ((1 << i) & mask) > 0 ) {
            sum += br[i];
        }
    }
    return sum;
}

void ispisi(int mask) {
    for(int i = 0; i < 20; ++i) {
        if( ((1 << i) & mask) > 0 ) {
            printf("%d ", br[i]);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &br[i]);
        }

        bool ok = false;
        printf("Case #%d:\n", test+1);
        for(int s1 = 1; s1 < (1<<20); ++s1) {
            int sum1 = sum(s1);
            for(int s2 = 1; s2 < (1<<20); ++s2) {
                if(s1 == s2) continue;
                int sum2 = sum(s2);
                if(sum1 == sum2) {
                    ok = true;
                    ispisi(s1);
                    ispisi(s2);
                    goto izlaz;
                }
            }
        }
    izlaz:
        if(!ok) {
            printf("Impossible\n");
        }
    }
    return 0;
}

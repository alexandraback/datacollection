#include <cstdio>
#define scanf(args...) (scanf(args) ? : 0)

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        
        int res = 0;
        for (int i=0; i<a; i++)
            for (int j=0; j<b; j++)
                if ((i&j) < k)
                    res++;
        printf("Case #%d: %d\n", test, res);
    }
}

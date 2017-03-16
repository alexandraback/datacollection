#include<cstdio>

using namespace std;

int main(){
    int T;
    int N, J;

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &J);
        printf("Case #%d:\n", t);
        long long NN = 1 << (N-1);
        for (long long c = NN + 1; J > 0; c += 2) {
            long long divs[10];
            for (int i=2;i<=10;i++) divs[i] = 0;
            int prime = 0;
            for (int base = 2; base <= 10 && (!prime); base++) {
                long long cc = 0;
                long long p = 1;
                long long aux = c;
                while (aux > 0) {
                    cc += (aux & 1) * p;
                    aux = aux >> 1;
                    p *= base;
                }
                for (long long d = 2; d*d <= cc; d++) {
                    if (cc % d == 0) {
                        divs[base] = d;
                        break;
                    }
                }
                if (divs[base] == 0) prime = 1;
            }
            if (prime) continue;
            J --;
            for (int i = N-1; i >= 0; i--)
                if (c & (1 << i)) printf("1");
                else printf("0");
            for (int i = 2; i <= 10; i++)
                printf(" %lld", divs[i]);
            printf("\n");
        }
    }
    return 0;
}

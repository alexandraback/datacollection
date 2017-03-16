#include <cstdio>
#define scanf(args...) (scanf(args) ? : 0)
const int LOG = 32;
typedef long long int LL;

void binary(int n, bool* res) {
    int it = LOG-1;
    while (n > 0) {
        res[it] = n%2;
        n /= 2, it--;
    }
}

LL solve(int a, int b, int k) {
    bool bina[LOG] = { };
    binary(a, bina);
    bool binb[LOG] = { };
    binary(b, binb);
    bool bink[LOG] = { };
    binary(k, bink);
    
    LL res = 0;
    for (int i=0; i<LOG; i++) {
        if (bina[i] == 1) {
            bina[i] = 0;
            for (int j=0; j<LOG; j++)
                if (binb[j] == 1) {
                    binb[j] = 0;
                    for (int p=0; p<LOG; p++) {
                        if (bink[p] == 1) {
                            //printf("i na bicie %d, j na %d, k na %d\n", LOG-i-1, LOG-j-1, LOG-p-1);
                            bink[p] = 0;
                            LL r1 = 1;
                            for (int s=0; s<=p; s++) {
                                if (s <= i && bina[s] == 0 && bink[s] == 1)
                                    r1 = 0;
                                else if (s <= j && binb[s] == 0 && bink[s] == 1)
                                    r1 = 0;
                                else if (s <= i && s <= j && (bina[s] & binb[s]) != bink[s])
                                    r1 = 0;
                                else if (s > i && s > j && bink[s] == 0)
                                    r1 *= 3;
                                else if (s > i && binb[s] == 0 && bink[s] == 0)
                                    r1 *= 2;
                                else if (s > j && bina[s] == 0 && bink[s] == 0)
                                    r1 *= 2;// printf("domnazam %d\n", s);
                            }

                            LL r2 = 1;
                            for (int s=p+1; s<LOG; s++) {
                                if (s > i)
                                    r2 *= 2;
                                if (s > j)
                                    r2 *= 2;
                            }
                            //printf("r1=%Ld, r2=%Ld\n", r1, r2);
                            res += r1*r2;

                            bink[p] = 1;
                        }
                    }
                    binb[j] = 1;
                }
            bina[i] = 1;
        }
    }
    
    return res;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        
        printf("Case #%d: %Ld\n", test, solve(a, b, k));
    }
}

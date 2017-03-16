#include <cstdio>
#include <cstring>

int A, B;
int bit;

inline int shift(int n){
    int i = n % 10;
    return i * bit + n / 10;
}

int main(){
#ifdef ILOAHZ
    //freopen("c.in", "r", stdin);
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small-attempt0.out", "w", stdout);
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &A, &B);
        bit = 1;
        for (int i = A / 10;bit <= i;bit *= 10);
        //printf("%d\n", bit);
        int s = 0;
        for (int n = A;n < B;n++){
            int m = shift(n);
            while (m != n){
                s += n < m && m <= B;
                m = shift(m);
            }
        }
        printf("Case #%d: %d\n", ++t, s);
    }
    return 0;
}

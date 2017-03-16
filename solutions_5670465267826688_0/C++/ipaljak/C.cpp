#include <cstdio>

#define MAXL 10005

using namespace std;

char s[MAXL];

int T;

bool is_neg(char x, char y) {
    if (x == 'i') return y == 'i' || y == 'k';
    if (x == 'j') return y == 'i' || y == 'j';
    if (x == 'k') return y == 'j' || y == 'k';
    return false;
}

char mul(char x, char y) {
    if (x == '1') return y;
    if (x == y) return '1';
    if (x != 'i' && y != 'i') return 'i';
    if (x != 'j' && y != 'j') return 'j';
    if (x != 'k' && y != 'k') return 'k';
}

void solve_small(int t) {

    int L, X;

    scanf("%d%d", &L, &X);
    scanf("%s", s);

    bool found_i = false, found_k = false, found_neg_one = false, neg = false;
    char rez = '1';

    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < L; ++j) {
            neg ^= is_neg(rez, s[j]);
            rez = mul(rez, s[j]);
            //printf("%c %d\n", rez, neg);
            if (rez == 'i' && !neg) found_i = true;
            if (rez == 'k' && !neg && found_i) found_k = true;
        }   
    }   

    if (rez == '1' && neg && found_i && found_k) found_neg_one = true;
    printf("Case #%d: ", t);
    if (found_neg_one && found_i && found_k) printf("YES\n"); else printf("NO\n"); 

}

int main(void) {

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) solve_small(t + 1);

    return 0;

}

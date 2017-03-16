#include <cstring>
#include <cstdio>

#define MAXL 10005

typedef long long llint;

using namespace std;

bool bio[MAXL][5][3];

char s[MAXL];

int T;

int rez_val(char x) {
    if (x == '1') return 0;
    return x - 'i' + 1;
}

bool is_neg(char x, char y) {
    if (x == 'i') return y == 'i' || y == 'k';
    if (x == 'j') return y == 'i' || y == 'j';
    if (x == 'k') return y == 'j' || y == 'k';
    return false;
}

char mul(char x, char y) {
    if (x == '1') return y;
    if (y == '1') return x;
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



void solve_large(int t) {

    memset(bio, false, sizeof bio);
    printf("Case #%d: ", t);

    int L;
    llint X;

    scanf("%d%lld", &L, &X);
    scanf("%s", s);

    char rez_L = '1';
    bool neg_L = false;

    for (int i = 0; i < L; ++i) {
        neg_L ^= is_neg(rez_L, s[i]);
        rez_L = mul(rez_L, s[i]);
    }

    
    char rez_all = '1';
    bool neg_all = false;

    llint exp = X;
    while (exp > 0) {
        if (exp & 1) {
            neg_all = neg_all ^ neg_L;
            neg_all ^= is_neg(rez_all, rez_L);
            rez_all = mul(rez_all, rez_L);
        }
        exp >>= 1;
        neg_L = false;
        neg_L = is_neg(rez_L, rez_L);
        rez_L = mul(rez_L, rez_L);
    }

    if (rez_all != '1' || !neg_all) {
        printf("NO\n");
        return;
    }

    int i_ind = 0, k_ind = 0, ind = 0, cnt = 1;
    char rez = '1';
    bool neg = false;
    
    while (true) {
    
        if (bio[ind][rez_val(rez)][neg]) break;
        bio[ind][rez_val(rez)][neg] = true;
        
        neg ^= is_neg(rez, s[ind]);
        rez = mul(rez, s[ind]);

        if (rez == 'i' && !neg && i_ind == 0) i_ind = cnt;
        if (rez == 'k' && !neg) {
            if (i_ind > 0) {
                printf("YES\n");
                return;
            }
            if (k_ind == 0) k_ind = cnt;
        }

        ++cnt;
        ++ind;
        ind %= L;

    }

    if (i_ind == 0 || k_ind == 0) {
        printf("NO\n"); 
        return;
    }
    
    --cnt;
    llint total = X * (llint) L; 
    llint koef = 1 + (i_ind - k_ind + 1) / cnt;
    llint next_k = (llint) k_ind + (llint) koef * cnt;

    if (next_k <= total) printf("YES\n"); else printf("NO\n");

}

int main(void) {

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) solve_large(t + 1);

    return 0;

}

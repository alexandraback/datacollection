#include <cstdio>

int L, X;
int explen, where_i, where_k;
char st[1111111], ex[1111111];
bool ans;

const int v_table[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2}, 
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};
const int s_table[4][4] = {
    { 1, 1, 1, 1},
    { 1,-1, 1,-1},
    { 1,-1,-1, 1},
    { 1, 1,-1,-1}
};

struct Num {
    int val, sign;
    Num() : val(0), sign(1) {}
    void mult_on_right(int x) {
        x -= 'h';
        int nv = v_table[val][x];
        int ns = s_table[val][x] * sign;
        sign = ns; val = nv;
    }
    void mult_on_left(int x) {
        x -= 'h';
        int nv = v_table[x][val];
        int ns = s_table[x][val] * sign;
        val = nv; sign = ns;
    }
    bool is_i() { return sign == 1 && val == 1; }
    bool is_k() { return sign == 1 && val == 3; }
    bool is_ijk() { return sign == -1 && val == 0; }
};

void expand() {
    int rep = X < 4 ? X : 4;
    int cur = 0;
    for (int r = 0; r < rep; ++r) 
        for (int i = 0; i < L; ++i)
            ex[cur++] = st[i];
    explen = cur;
}

void ready() {
    scanf("%d%d", &L, &X);
    scanf("%s", &st);
}

bool find_i() {
    Num sofar;
    for (int i = 0; i < explen; ++i) {
        sofar.mult_on_right(ex[i]);
        if (sofar.is_i()) {
            where_i = i;
            return true;
        }
    }
    return false;
}

bool find_k() {
    Num sofar;
    for (int i = explen - 1; i >= 0; --i) {
        sofar.mult_on_left(ex[i]);
        if (sofar.is_k()) {
            where_k = i;
            return true;
        }
    }
    return false;
}

bool find_j() {
    if (where_i >= where_k && X <= 4) return false;
    Num sum;
    int eqv_len = (X % 4) * L;
    for (int i = 0; i < eqv_len; ++i) 
        sum.mult_on_right(ex[i]);
    return sum.is_ijk();
}
        
void work() {
    expand();
    ans = false;
    if (!find_i()) return;
    if (!find_k()) return;
    if (!find_j()) return;
    ans = true;
}

void finish(int cas) {
    printf("Case #%d: %s\n", cas,
        ans ? "YES" : "NO");
}

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        ready(); 
        work();
        finish(cas);
    }
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>

static int mul_tab[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2,-1, 4,-3},
    {0, 3,-4,-1, 2},
    {0, 4, 3,-2,-1}
};
static int Div_tab[5][5];

int mul(int a, int b) {
    bool neg = (a < 0) ^ (b < 0);
    return mul_tab[abs(a)][abs(b)] * (neg ? -1 : 1);
}

int Div(int a, int b) {
    bool neg = (a < 0) ^ (b < 0);
    return Div_tab[abs(a)][abs(b)] * (neg ? -1 : 1);
}

void init_Div() {
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            for (int d = 1; d <= 4; d++)
                if (abs(mul(j, d)) == i)
                    Div_tab[i][j] = (mul(j, d) < 0 ? -d : d);
}

int conv(char c) {
    switch (c) {
        case '1': return 1;
        case 'i': return 2;
        case 'j': return 3;
        case 'k': return 4;
        default: return 0;
    };
}

bool solve(char *_str, int len, long long x) {

    static char str[160010];
    static int acc[160010];

    if (x > 12)
        x = (x - 12) % 4 + 12;
    for (int i = 0; i < x; i++)
        strcpy(str + i * len, _str);

    int nlen = len * x;
    acc[0] = conv(str[0]);
    for (int i = 1; i < nlen; i++)
        acc[i] = mul(acc[i - 1], conv(str[i]));


    static bool cap_i[160010];

    for (int i = 0; i < nlen; i++) {
        cap_i[i] = (acc[i] == conv('i'));
    }

    for (int i = 1, icap = 0; i < nlen - 1; i++) {
        if (cap_i[i - 1])
            icap |= (1 << (acc[i - 1] + 4));
        for (int j = 0; j <= 8; j++)
            if ((icap & (1 << j)) && Div(acc[i], j - 4) == conv('j'))
                if (Div(acc[nlen - 1], acc[i]) == conv('k'))
                    return true;
    }
    return false;

}

int main() {

    int T;
    scanf("%d", &T);

    init_Div();

    for (int t = 1; t <= T; t++) {

        int len;
        long long x;
        scanf("%d %lld", &len, &x);

        static char buf[10010];
        scanf("%s", buf);

        printf("Case #%d: %s\n", t, solve(buf, len, x) ? "YES" : "NO");

    }

}

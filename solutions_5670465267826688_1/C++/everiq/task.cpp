#include <cstdio>
#include <cassert>
#include <string>

using namespace std;

enum {
    E_0,
    E_1,
    E_I,
    E_J,
    E_K,
};

const int MUL[6][6] = {
             /* E_0   E_1   E_I   E_J   E_K */
    /* E_0 */ { E_0,  E_0,  E_0,  E_0,  E_0 },
    /* E_1 */ { E_0,  E_1,  E_I,  E_J,  E_K },
    /* E_I */ { E_0,  E_I, -E_1,  E_K, -E_J },
    /* E_J */ { E_0,  E_J, -E_K, -E_1,  E_I },
    /* E_K */ { E_0,  E_K,  E_J, -E_I, -E_1 }
};

template <typename A>
inline int abs(A a) {
    return (a >= 0) ? a : -a;
}

static int char2ijk(char c) {
    switch (c) {
        case '1': return E_1;
        case 'i': return E_I;
        case 'j': return E_J;
        case 'k': return E_K;
        default: assert(nullptr == "char2ijk: invalid character");
    }
    return 0;
}

static string pp(int i) {
    static char c[] = "01ijk";
    return string(i < 0 ? "-" : "") += c[abs(i)];

}

static int mul(int a, int b) {
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;
    return sign * MUL[abs(a)][abs(b)];
}

int main() {
    int t;
    scanf("%d", &t);
    for (int zz = 1; zz <= t; ++zz) {
        long long int l, x;
        scanf("%lld %lld\n", &l, &x);

        int mul_i = E_1;
        int mul_j = E_1;
        bool rem = false;
        int mul_total = E_1;

        int pass = 0;

        while (pass < x && pass < 6) {
            if (pass > 0) fseek(stdin, -l, SEEK_CUR);
            ++pass;
            char c;
            for (long long int i = 0; i < l; ++i) {
                scanf("%c", &c);
                int f = char2ijk(c);

                if (pass == 1) mul_total = mul(mul_total, f);
                if (mul_i != E_I) mul_i = mul(mul_i, f);
                else if (mul_j != E_J) mul_j = mul(mul_j, f);
                else rem = true;
                // printf(">> %s i:%s j:%s t:%s\n", pp(f).c_str(), pp(mul_i).c_str(), pp(mul_j).c_str(), pp(mul_total).c_str());
            }

            if (mul_i != E_I && pass > 3) break;
            if (mul_j != E_J && pass > 6) break;
        }

        rem = rem || (pass < x);
        bool ok = mul_i == E_I && mul_j == E_J && rem;

        if (ok) {
            while (x % 2 == 0) {
                x /= 2;
                mul_total = mul(mul_total, mul_total);
            }
            ok = mul_total == -E_1;
        }

        printf("Case #%d: %s\n", zz, ok ? "YES" : "NO");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

#define DIGITS 7

int T;
int a, b, bd;
unsigned char bs[DIGITS];

struct Digitals {
    unsigned char *p;
    int d;
    Digitals(unsigned char *p, int d) : p(p), d(d) { }
    bool operator= (const Digitals& rhs) const {
        return (d == rhs.d) && memcmp(p, rhs.p, d) == 0;
    }
    bool operator< (const Digitals& rhs) const {
        return d < rhs.d || (d == rhs.d && memcmp(p, rhs.p, d) < 0);
    }
};

int count(int v) {
    int d = 0;
    unsigned char a[DIGITS * 3] = { 0 };

    for (int x = v; x; x /= 10) a[DIGITS-(++d)] = x % 10;

    memcpy(a + DIGITS, a + DIGITS - d, d);

    set<Digitals> ds;
    for (int i = 1; i < d; ++i)
        if (memcmp(a + DIGITS - i, a + DIGITS, d) > 0 
                && a[DIGITS-i] > 0 
                && ((d < bd) || (d == bd && memcmp(a + DIGITS - i, bs, d) <= 0))
           ) ds.insert(Digitals(a + DIGITS - i, d));

    return ds.size();
}

int main(int argc, char const *argv[]) {
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        scanf("%d%d", &a, &b);

        long c = 0;

        bd = 0;
        memset(bs, 0, sizeof(bs));
        for (int x = b; x; x /= 10) bs[DIGITS-(++bd)] = x % 10;
        memmove(bs, bs + DIGITS - bd, bd);

        for (int j = a; j < b; ++j) c += count(j);
        printf("Case #%d: %ld\n", i, c);
    }
    

    return 0;
}

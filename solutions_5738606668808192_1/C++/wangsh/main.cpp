#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

//global constants
const int INF = 1<<29;
const double EPS = 1e-8;
typedef __int64 LL;

//local constants
const int MAX = 1000000;
const int N = 32;
int COUNT = 500;
int PRIME[MAX / 10];
bool removed[MAX];
int NUM = 0;

bool divid(LL stat, LL prim, int base) {
    LL ret = 1;
    for (LL i = N-3; i >= 0; --i) {
        ret *= base;
        if (stat & (1LL << i)) ret += 1;
        ret %= prim;
    }
    ret = ret*base+1;
    ret %= prim;

    return (ret == 0);
}

//LL val_jamcoin(v) {
//
//}

LL checkFactor(LL v, int base) {
//    LL val = val_jamcoin(v);
    for (int i = 0; i < NUM && PRIME[i] < v; ++i)
        if (divid(v, PRIME[i], base))
            return PRIME[i];
    return -1;
}

void print_coinjam(LL v) {
    putchar('1');
    for (LL i = N-3; i >= 0; --i)
        if (v & (1LL<<i)) putchar('1');
        else putchar('0');
    putchar('1');
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    PRIME[NUM++] = 2;
    for (LL i = 3; i < MAX; i+=2)
        if (!removed[i]) {
            PRIME[NUM++] = i;
            for (LL j = i*i; j < MAX; j += i)
                removed[j] = 1;
        }
//    printf("N = %d\n", NUM);

    printf("Case #1:\n");

    LL minV = 0, maxV = (1LL<<(N-2))-1;
    LL div[12];
//    printf("minV = %I64d, maxV = %I64d\n", minV, maxV);
//    return 0;

    for (LL num = minV; num <= maxV && COUNT > 0; ++num) {
//        printf("view = %I64d\n", view);
//        return 0;
        bool valid = true;
//        printf("start view %I64d\n", view);
//        print_coinjam(num);
//        putchar('\n');
        for (int base = 2; base <= 10; ++base) {
            div[base] = checkFactor(num, base);
//            printf("div[%d] = %I64d\n", base, div[base]);
            if (div[base] == -1) {
                valid = false;
                break;
            }
//            printf("%I64d %I64d\n", view, val);
        }
        if (valid) {
            COUNT--;
            print_coinjam(num);
            for (int i = 2; i <= 10; ++i) printf(" %I64d", div[i]);
            printf("\n");
        }
    }

    if (COUNT != 0) printf("NOT ENOUGH\n");

    return 0;
}

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
const int N = 16;
int COUNT = 50;
int PRIME[MAX / 10];
bool removed[MAX];
int NUM = 0;

LL checkFactor(LL v) {
    for (int i = 0; i < NUM && PRIME[i] < v; ++i)
        if (v % PRIME[i] == 0)
            return PRIME[i];
    return -1;
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
        LL view = 1;
        for (int i = N-3; i >= 0; --i) {
            LL bit = 1LL << i;
            view *= 10;
            if (bit & num) view += 1;
//            printf("%I64d\n", view);
        }
        view = view*10 + 1;
//        printf("view = %I64d\n", view);
//        return 0;
        bool valid = true;
//        printf("start view %I64d\n", view);
        for (int base = 2; base <= 10; ++base) {
            LL tmp = view;
            LL val = 0;
            LL sbase = 1;
            while (tmp) {
                val += tmp%10*sbase;
                sbase *= base;
                tmp /= 10;
//                printf("val = %I64d base = %d\n", val, base);
            }
//            printf("val in base %d = %I64d\n", base, val);
            div[base] = checkFactor(val);
            if (div[base] == -1) {
                valid = false;
                break;
            }
//            printf("%I64d %I64d\n", view, val);
        }
        if (valid) {
            COUNT--;
            printf("%I64d", view);
            for (int i = 2; i <= 10; ++i) printf(" %I64d", div[i]);
            printf("\n");
        }
    }

    return 0;
}

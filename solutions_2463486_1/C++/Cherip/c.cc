#include <stdio.h>
#include <math.h>

long long  para(long long  a) {
    int t[1000];
    long long  b = a;
    int len = 0;
    while (b) {
        t[len++] = b % 10;
        b = b / 10;
        //printf("%d ", t[])
    }

    for (int i = 0; i < len /2; i++) {
        if (t[i] != t[len - 1- i])
            return 0;
    }
    return 1;
}

long long pali[1000000];
int idx = 0;

void get_pali() {
    idx = 0;
    long long up =10;
    for (int j = 0; j < 6;j++) up *= 10;
    //printf("%lld\n", up);
    for (long long i = 1; i < up; i++) {
        if (para(i)) {
            if (para(i * i)) {
                pali[idx++] = i * i;
                //printf("%lld %lld\n", i, i*i);
            }
        }
    }
    //printf("%d\n", idx);
}

int judge(long long a) {
    if (!para(a)) return 0;
    //printf("??%d\n", a);
    long long t = (long long)sqrt(a);
    if (t *t != a) return 0;
    //printf(">>%d\n", t);
    if (!para(t)) return 0;
    return 1;
}

int judge(long long a, long long b) {
    int count = 0;
    for (int i = 0; i < idx; i++) {
        if (pali[i] >= a && pali[i] <= b)
            count++;
    }
    return count;
}

int main() {
    freopen("C-large-1.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    //printf("%d\n", t);

    get_pali();
//return 1;
    int idx = 1;
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        //int count = 0;
        //for (int i = a; i <= b;i++)
        //    if (judge(i)) count++;

        //printf("Case #%d: %d\n", idx++, count);
        printf("Case #%d: %d\n", idx++, judge(a, b));
    }
}

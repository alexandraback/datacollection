#include <stdio.h>
#include <math.h>

int para(int a) {
    int t[10];
    int b = a;
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

int judge(int a) {
    if (!para(a)) return 0;
    //printf("??%d\n", a);
    int t = (int)sqrt(a);
    if (t *t != a) return 0;
    //printf(">>%d\n", t);
    if (!para(t)) return 0;
    return 1;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    //printf("%d\n", t);
    int idx = 1;
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int count = 0;
        for (int i = a; i <= b;i++)
            if (judge(i)) count++;

        printf("Case #%d: %d\n", idx++, count);
    }
}

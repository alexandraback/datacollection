#include <cstdio>
#include <cstdlib>

int e10[10];

int get_len(int x) {

    int res = 0;
    while (x) res++, x /= 10;
    return res;
}

int count(int x, int upper) {

    int i = x, res = 0;
    int e = e10[get_len(x) - 1];

    do
    {
        if (i > x && i <= upper) res++;  
        i = i % 10 * e + i / 10;
    }
    while (i != x);
    return res;
}

void pre_work() {

    e10[0] = 1;
    for (int i = 1; i < 10; i++)
        e10[i] = e10[i - 1] * 10;
}

void work() {

    int A, B;
    int ans = 0;
    scanf("%d %d", &A, &B);
    for (int i = A; i <= B; i++)
        ans += count(i, B);
    printf("%d\n", ans);
}

int main() {

    pre_work();

    int case_num;
    scanf("%d", &case_num);

    for (int i = 0; i < case_num; i++)
    {
        printf("Case #%d: ", i + 1);
        work();
    }

    return 0;
}

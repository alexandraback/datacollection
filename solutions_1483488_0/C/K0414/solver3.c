#include <stdio.h>
#include <stdlib.h>

int get_pair(int n, int B);
int next(int n);

int main()
{
    int i, j, T, A, B;
    int sum;

    scanf("%d", &T);
    for(i = 0; i < T; i++) {
        scanf("%d%d", &A, &B);
        sum = 0;
        for(j = A; j < B; j++) {
            sum += get_pair(j, B);
        }

        printf("Case #%d: %d\n", i + 1, sum);
    }

    return 0;
}

int get_pair(int n, int B)
{
    int m, cnt;

    m = next(n);
    cnt = 0;
    while(m != n) {
        if(m > n && m <= B)
            cnt++;
        m = next(m);
    }

    return cnt;
}

int next(int n)
{
    char str[10];
    char *p, c;

    sprintf(str, "%d", n);
    p = str;

    do {
        while(*p)
            p++;

        c = *--p;
        while(p != str) {
            *p = *(p - 1);
            p--;
        }
        *p = c;
    } while(*str == '0');

    return atoi(str);
}


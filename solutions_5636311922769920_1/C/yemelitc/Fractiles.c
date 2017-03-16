#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int x, T;
    int i, j, K, C, S;
    unsigned long long a, b, c, d;

    scanf("%u", &T);

    for(x=1; x<=T; x++)
    {
        scanf("%d %d %d", &K, &C, &S);
        if(C>K) C=K;
        j = K%C;

        a=0; b=0; c=0; d=1;
        for(i=1; i<C; i++)
        {
            c += d;
            a += c;
            if(j && i<j) b += c;
            d *= K;
        }

        i = K/C;
        if(j) i++;
        else b=a;
        //printf("\nK=%d  C=%d  S=%d  i=%d  a=%llu  b=%llu  c=%llu  d=%llu\n", K, C, S, i, a, b, c, d);

        printf("Case #%d:", x);
        if(S<i) { printf(" IMPOSSIBLE\n"); continue; }
        S=i;
        for(i=1; i<S; i++)
        { printf(" %llu", a+1); a += C*d; }
        printf(" %llu\n", (S-1)*C*d + b+1);
    }
}


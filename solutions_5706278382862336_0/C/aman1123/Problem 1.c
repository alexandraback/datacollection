#include<stdio.h>
int isPowerOfTwo(int x)
{
  return x && (!(x&(x-1)));
}
int main()
{
    int t, k, a, b, count;
    scanf("%d", &t);
    for(k = 1; k <= t; k++)
    {
        count = 0;
        scanf("%d/%d", &a, &b);
        if(!isPowerOfTwo(b))
        {
            printf("Case #%d: impossible\n", k);
            continue;
        }
        int div = a / b;
        while(div < 1)
        {
            b /= 2;
            div = a / b;
            count++;
        }
        printf("Case #%d: ", k);
        printf("%d\n", count);
    }
    return 0;
}

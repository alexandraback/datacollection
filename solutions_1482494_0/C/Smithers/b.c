#include <stdio.h>

#define MAXN 1000

struct level {
    int a, b, x;
};

int cmplevel(const void *p, const void *q)
{
    const struct level *p_ = p, *q_ = q;
    return p_->b > q_->b ? -1 : p_->b < q_->b ? 1 : 0;
};

int main()
{
    int t, c;
    int n;
    struct level l[MAXN];
    int i, stars, result, loop;
    
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        scanf("%d", &n);
        for (i=0; i<n; i++)
            scanf("%d%d", &l[i].a, &l[i].b), l[i].x = 0;
        
        qsort(l, n, sizeof(struct level), cmplevel);
        result = 0;
        stars = 0;
        do
        {
            loop = 0;
            for (i=0; i<n; i++)
                if (l[i].x < 2)
                    if (stars >= l[i].b)
                    {
                        stars += 2 - l[i].x;
                        l[i].x = 2;
                        result++;
                        loop |= 1;
                    }
                    else
                        loop |= 2;
            
            for (i=0; i<n && loop==2; i++)
                if (l[i].x < 1 && stars >= l[i].a)
                {
                    stars++;
                    l[i].x = 1;
                    result++;
                    loop |= 1;
                }
        } while (loop == 3);
        
        if (loop & 2)
            printf("Case #%d: Too Bad\n", c);
        else
            printf("Case #%d: %d\n", c, result);
    }
    return 0;
}

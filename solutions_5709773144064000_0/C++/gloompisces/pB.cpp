#include <stdio.h>

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    
    double C, F, X, time, prod;
    int farm = 0;
    double ans;
    
    int cases;
    scanf("%d", &cases);
    for (int case_index = 1; case_index <= cases; case_index++)
    {
        scanf("%lf %lf %lf", &C, &F, &X);
        time = 0;
        ans = X / 2.0;
        farm = 0;
        prod = 2.0;
        
        for (;;)
        {
            time += C / prod;
            farm++;
            prod += F;
            
            if (ans > time + X / prod)
            {
                ans = time + X / prod;
            }
            else
            {
                break;
            }
        }
        printf("Case #%d: %.7f\n", case_index, ans);
    }
    
    return 0;
}

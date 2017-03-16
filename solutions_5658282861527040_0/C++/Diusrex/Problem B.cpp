#include <cstdio>


int main()
{
    int A, B, K, T;
    
    scanf("%d", &T);
    
    
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d %d %d", &A, &B, &K);
        
        
        int count = 0;
        
        for (int a = 0; a < A; ++a)
        {
            for (int b = 0; b < B; ++b)
            {
                if ((a&b) < K)
                    ++count;
            }
        }
        
        
        printf("Case #%d: %d\n", t, count);
    }


}
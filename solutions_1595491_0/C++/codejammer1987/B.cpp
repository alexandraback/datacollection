#include <cstdio>

int cases;
int N, S, p;
int total;
int curr;

int main()
{
    scanf("%d", &cases);
    
    for (int i = 1; i <= cases; i++)
    {
        scanf("%d %d %d", &N, &S, &p);
        
        total = 0;
        while (N-- > 0)
        {
              scanf("%d", &curr);
                            
              if (curr / 3 >= p || (curr >= p && curr / 3 == p-1 && curr % 3 >= 1))
                 total++;
              else if (S > 0 && curr >= p && ((curr / 3 == p-1 && curr % 3 == 0) ||
                           (curr / 3 == p-2 && curr % 3 == 2)))
              {
                  total++;
                  S--;
              }
        }       
        printf("Case #%d: %d\n", i, total); 
    }
    
    return 0;
}

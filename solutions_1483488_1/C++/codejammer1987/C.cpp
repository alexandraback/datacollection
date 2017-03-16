#include <cstdio>
#include <set>
#include <cmath>
#include <utility>

using namespace std;

int next_int(int input)
{
    if (input == 0)
       return input;
    
    int places = (int)log10(input)+1;
    
    while (input % 10 == 0)
          input /= 10;
          
    return input / 10 + (input%10) * (int)pow(10.0, places-1);
}

set<pair<int, int> > encountered;
int cases;
int A, B;
int t;

int main()
{
    scanf("%d", &cases);
    
    for (int i = 1; i <= cases; i++)
    {
        scanf("%d %d", &A, &B);
        encountered.clear();
        
        for (int j = A; j <= B; j++)
        {
              t = j;
              while ((t = next_int(t)) != j)
              {
                    if (t >= A && t <= B)
                       encountered.insert(make_pair(min(j, t), max(j, t)));
              }
        }
        
        printf("Case #%d: %d\n", i, encountered.size());
//        for (set<int>::iterator it = encountered.begin(); it != encountered.end(); it++)
//            printf("%d ", *it);
//        printf("\n");
    }
    
    return 0;
}

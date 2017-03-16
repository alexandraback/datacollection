#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int lp=1;lp<=t;++lp)
    {
        int n, s, p;
        scanf("%d %d %d", &n, &s, &p);
        
        int resp = 0;
        for(int i=0;i<n;++i)
        {
            int score;
            scanf("%d", &score);
            if(score >= p + 2*max(0, p-1))
            {
                ++resp;
            }
            else if(score >= p + 2*max(0, p-2))
            {
                if (s > 0)
                {
                    --s;
                    ++resp;
                }
            }
        }
        
        printf("Case #%d: %d\n", lp, resp);
    }
    
    return 0;
}
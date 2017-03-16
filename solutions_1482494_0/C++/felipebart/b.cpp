#include <cstdio>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct level
{
    int cost1;
    int cost2;
    bool firstdone;
};

int main()
{
    int t;
    scanf("%d", &t);
    for(int lp=1;lp<=t;++lp)
    {
        int n;
        scanf("%d", &n);
        vector<level> levels(n);
        for(level& l : levels)
        {
            scanf("%d %d", &l.cost1, &l.cost2);
            l.firstdone = false;
        }
        
        sort(levels.begin(), levels.end(), 
             [](const level& a, const level& b) -> bool
             {
                 return (a.cost2 != b.cost2) ? (a.cost2 < b.cost2) : (a.cost1 > b.cost1);
             });
        
        for(int i=1;i<n;++i)
        {
            assert(levels[i].cost2 >= levels[i-1].cost2);
        }
        
        int stars = 0;
        int ret = 0;
        
        int lvl2 = 0;
        while(lvl2 < n)
        {
            if(stars >= levels[lvl2].cost2)
            {
                ++ret;
                stars += (levels[lvl2].firstdone ? 1 : 2);
                ++lvl2;
            }
            else
            {
                /*
                auto it = find_if(levels.rbegin(), levels.rend() - lvl2,
                                  [&](const level& l) -> bool
                                  {
                                      return (!l.firstdone && (l.cost1 <= stars));
                                  });
                                  */
                
                auto it = levels.end();
                for(int i=n-1;i>=lvl2;--i)
                {
                    if(!levels[i].firstdone && (levels[i].cost1 <= stars))
                    {
                        it = levels.begin() + i;
                        break;
                    }
                }
                
                if(it == levels.end())
                {
                    break;
                }
                else
                {
                    ++ret;
                    ++stars;
                    it->firstdone = true;
                    //printf("%d\n", it - levels.begin());
                }
            }
        }
        
        printf("Case #%d: ", lp);
        if(lvl2 == n)
        {
            printf("%d\n", ret);
        }
        else
        {
            printf("Too Bad\n");
        }
    }
    return 0;
}
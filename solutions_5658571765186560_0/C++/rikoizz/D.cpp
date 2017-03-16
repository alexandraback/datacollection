#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int x,r,c;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int _;scanf("%d",&_);
    for (int __ = 1;__ <= _;__++)
    {
        scanf("%d %d %d",&x,&r,&c);
        if (r > c) swap(r,c);
        if (x == 1)
        {
            printf("Case #%d: GABRIEL\n",__);
        }
        if (x == 2)
        {
            if (r % 2 == 0 || c % 2 == 0)
                printf("Case #%d: GABRIEL\n",__);
            else
                printf("Case #%d: RICHARD\n",__);
        }
        if (x == 3)
        {
            if ((r == 3 && c >= 2) || (c == 3 && r >= 2))
                printf("Case #%d: GABRIEL\n",__);
            else
                printf("Case #%d: RICHARD\n",__);
        }
        if (x == 4)
        {
            if ((r == 4 && c >= 3) || (c == 4 && r >= 3))
                printf("Case #%d: GABRIEL\n",__);
            else
                printf("Case #%d: RICHARD\n",__);
        }
    }
}

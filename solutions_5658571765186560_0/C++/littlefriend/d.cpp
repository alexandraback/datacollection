#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int s[7] = {0,1,1,2,3,4,5};
int main(int argv, char** argc)
{
    int T,t,a,x,y;
    if (argv > 1)
        freopen(argc[1], "r", stdin);
    if (argv > 2)
        freopen(argc[2], "w", stdout);
    scanf("%d",&T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d%d",&a,&x,&y);
        if (x>y) swap(x,y);
        printf("Case #%d: ",t);
        if (x*y%a || y<a || a>6 || (x<s[a]))
        {
            printf("RICHARD\n");
        } else
        {
            printf("GABRIEL\n");
        }
    }
}
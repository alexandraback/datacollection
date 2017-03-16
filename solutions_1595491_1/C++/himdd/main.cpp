#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("2.in","r",stdin);
    //freopen("o.txt","w",stdout);
    int c,n,s,p,t;
    scanf("%d", &c );
    for(int ca = 1; ca <= c; ca++)
    {
        int scnt=0,total=0;
        scanf("%d%d%d", &n, &s, &p);
        for(int i = 0; i < n; ++ i)
        {
            scanf("%d", &t);
            if(p > t)continue;
            if(3*p - 4 == t || 3*p - 3 == t)
            {
                if(scnt < s)
                {
                    ++scnt;
                    ++total;
                }
            }
            else if( t >= 3*p - 2 )
                ++total;
        }
        printf("Case #%d: %d\n",ca, total);
    }
    return 0;
}

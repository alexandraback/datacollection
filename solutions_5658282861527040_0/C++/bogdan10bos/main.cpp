#include <cstdio>

using namespace std;
int T, TT, i, j, t, a, b, c;
int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d", &T);
    TT=T;
    while(T--)
    {
        printf("Case #%d: ", TT-T);
        scanf("%d%d%d", &a, &b, &c);
        t=0;
        for(i=0;i<a;i++)
            for(j=0;j<b;j++)
                if((i&j)<c) t++;
        printf("%d\n", t);
    }
    return 0;
}

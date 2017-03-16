#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,X,R,C,tot,ntest=1;
    scanf("%d\n",&T);
    while(T--)
    {
        scanf("%d %d %d\n",&X,&R,&C);
        tot = R * C;
        if(X <= 3)
        {
            if(tot % X == 0)
                printf("Case #%d: GABRIEL\n",ntest++);
            else 
                printf("Case #%d: RICHARD\n",ntest++);
        }
        else if(X >= 7 || R < X || C < X || tot % X != 0)
            printf("Case #%d: RICHARD\n",ntest++);
        else
            printf("Case #%d: GABRIEL\n",ntest++);
    }
    return 0;
}

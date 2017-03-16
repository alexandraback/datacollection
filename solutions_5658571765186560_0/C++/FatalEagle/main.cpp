#include <bits/stdc++.h>

using namespace std;

int X, R, C;

void _main()
{
    scanf("%d%d%d", &X, &R, &C);
    if(R>C)
        swap(R, C);
    if(X>max(R, C) || X>6 || (R*C)%X!=0 || (X+1)/2>min(R, C))
        printf("RICHARD\n");
    else if(X==1)
        printf("GABRIEL\n");
    else if(X==2)
    {
        if((R*C)&1)
            printf("RICHARD\n");
        else
            printf("GABRIEL\n");
    }
    else if(X==3)
    {
        if(R%3==0 && C>1)
            printf("GABRIEL\n");
        else if(C%3==0 && R>1)
            printf("GABRIEL\n");
        else
            printf("RICHARD\n");
    }
    else if(X==4)
    {
        if(R==2)
            printf("RICHARD\n");
        else if(R%4==0 || C%4==0)
            printf("GABRIEL\n");
    }
}

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        _main();
    }
    return 0;
}

#include<cstdio>

int main(int argc, char* argv[])
{
    int T=0;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        int X, R, C;
        scanf("%d %d %d", &X, &R, &C);

        if((R*C) % X != 0)
            printf("Case #%d: RICHARD\n", i+1);
        else if( X > R && X > C)
            printf("Case #%d: RICHARD\n", i+1);
        else if( X > R*2 || X > C*2)
            printf("Case #%d: RICHARD\n", i+1);
        else
        {
            if(R < C)
            {
                int tmp = C;
                C = R;
                R = tmp;
            }

            if( (R*C == 2*X) && (X >= 2*C) && (X >= 4))
                printf("Case #%d: RICHARD\n", i+1);
            else
                printf("Case #%d: GABRIEL\n", i+1);
        }

    }
    return 0;
}


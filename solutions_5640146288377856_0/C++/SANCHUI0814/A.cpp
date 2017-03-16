#include<cstdio>
#include<cmath>



int main(int argc, char* argv[])
{
    int T;
    scanf("%d", &T);


    for(int i=0; i<T; i++)
    {
        int R, C, W;
        scanf("%d %d %d", &R, &C, &W);

        int res = C/W;
        if(C % W == 0)
            res = res + W - 1;
        else
            res = res + W;

        printf("Case #%d: %d\n", i+1, res);
    }
}


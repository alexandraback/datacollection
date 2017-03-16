#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

bool can(int a , int b)
{
    return (a % b == 0) ? true : false;
}

bool ret[5][5][5];

int main()
{
    freopen("D-small-attempt0.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    for(int i = 1;i < 5;i++)
        for(int j = 1;j < 5;j++)
            for(int k = 1;k < 5;k++)
                if(can(i * j , k))
                    ret[j][i][k] = true;
                else
                    ret[j][i][k] = false;

    ret[3][1][3] = ret[4][1][4] = ret[2][2][4] = ret[4][2][4] = ret[1][3][3] = ret[1][4][4] = ret[2][4][4] = false;

    int T , c = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++c;
        int X , R , C;
        scanf("%d%d%d" , &X , &R , &C);

        printf("Case #%d: " , c);
        printf(ret[C][R][X] ? "GABRIEL\n" : "RICHARD\n");
    }
}

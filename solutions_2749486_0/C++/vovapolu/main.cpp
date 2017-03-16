#include <iostream>
#include <cstdio>

using namespace std;

int t;

void W()
{
    printf("EW");
}

void E()
{
    printf("WE");
}

void N()
{
    printf("SN");
}

void S()
{
    printf("NS");
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i <t; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("Case #%d: ", i + 1);
        if (x > 0)
            for (int i = 0; i < x; i++)
                E();

        if (x < 0)
            for (int i = 0; i < -x; i++)
                W();

        if (y > 0)
            for (int i = 0; i < y; i++)
                N();

        if (y < 0)
            for (int i = 0; i < -y; i++)
                S();
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t;

int a, b, c;

int main()
{
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
        scanf("%d%d%d", &a, &b, &c);
        printf("Case #%d: ", h);
        if (((b*c)%a) || a>=7 || a>max(b, c) || (a>>1)>=min(b, c))
        {
            printf("RICHARD\n");
        }
        else
        {
            printf("GABRIEL\n");
        }
    }
    return 0;
}

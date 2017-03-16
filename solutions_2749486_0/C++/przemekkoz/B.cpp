//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t;
int x,y;

int main()
{
    scanf("%d" ,&t);

    for(int ti = 1;ti <= t;ti++)
    {
        scanf("%d%d", &x, &y);
        printf("Case #%d: ", ti);

        int poz = 1;

        for(int i = 1;i <= abs(x);i++)
        {
            if(x < 0) printf("EW");
            else printf("WE");
            poz += 2;
        }

        for(int i = 1;i <= abs(y);i++)
        {
            if(y < 0) printf("NS");
            else printf("SN");
            poz += 2;
        }

        printf("\n");
    }

    return 0;
}

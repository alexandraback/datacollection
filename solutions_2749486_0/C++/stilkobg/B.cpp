#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        int X,Y;
        scanf("%d%d",&X,&Y);
        printf("Case #%d: ",t);
        int x=0,y=0;
        if(X<0)
        {
            while(x!=X)
            {
                printf("EW");
                x--;
            }
        }
        else
        {
            while(x!=X)
            {
                printf("WE");
                x++;
            }
        }
        if(Y<0)
        {
            while(y!=Y)
            {
                printf("NS");
                y--;
            }
        }
        else
        {
            while(y!=Y)
            {
                printf("SN");
                y++;
            }
        }
        printf("\n");
    }
    return 0;
}

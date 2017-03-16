#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int muldata[5][5] = {{0,0,0,0,0},
                       {0,1,2,3,4},
                       {0,2,-1,4,-3},
                       {0,3,-4,-1,2},
                       {0,4,3,-2,-1}};
int read(char input)
{
    switch (input)
    {
        case ('i'):return 2; break;
        case ('j'):return 3; break;
        case ('k'):return 4; break;
    }
    return 0;
}

int mul(int a,int b)
{
    int temp = 1;
    if (a < 0)
    {
        temp *= -1;
        a = -a;
    }
    if (b < 0)
    {
        temp *= -1;
        b = -b;
    }
    return muldata[a][b] * temp;
}

int data[110000];
int main()
{
    int times;
    freopen("C-large.in","r",stdin);
    freopen("C-large.txt","w",stdout);
    scanf("%d",&times);
    for (int t = 1; t <= times; t++)
    {
        int l,x;
        memset(data,0,sizeof(data));
        scanf("%d %d",&l,&x);
        char tt;
        scanf("%c",&tt);
        for (int i = 0; i < l; i++)
        {
            scanf("%c",&tt);
            data[i] = read(tt);
        }
        int temp = 1;
        for (int i = 0; i < (x%4); i++)
        {
            for (int j = 0; j < l; j++)
                temp = mul(temp,data[j]);
        }
        if (temp != -1)
        {
            printf("Case #%d: NO\n",t);
            continue;
        }
        if (x > 10) x = 10;
        for (int i = 1; i < x; i++)
        {
            for (int j = 0 ; j < l; j++)
            {
                 data[i*l+j] = data[j];
            }
        }
        l = l * x;
        int left = -1;
        temp = 1;
        int i;
        for (i = 0; i < l; i++)
        {
            temp = mul(temp,data[i]);
            if (temp == 2) break;
        }
        if (i == l){
            printf("Case #%d: NO\n",t);
            continue;
        }
        temp = 1;left = i;
        for (i = l-1; i >= 0; i--)
        {
            temp = mul(data[i],temp);
            if (temp == 4) break;
        }
        if (i == -1 || i <= left+1 )
        {
            printf("Case #%d: NO\n",t);
            continue;
        }
        printf("Case #%d: YES\n",t);
    }
}

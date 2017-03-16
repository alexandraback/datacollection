#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int data[64][3];
bool check[64];
int main()
{
    freopen("data.txt","r",stdin);
    freopen("ans.txt","w",stdout);

    int t;
    int n,m,k;
    int product;
    scanf("%d",&t);
    printf("Case #1: \n");
    scanf("%d",&t);
    scanf("%d %d %d",&n,&m,&k);
    int count = 0;
    for (int i = 2; i<=5; i++)
        for (int j = i; j <= 5; j++)
            for (int l = j; l <= 5; l++)
            {
                data[count][0] = i;
                data[count][1] = j;
                data[count++][2] = l;
            }
    for (;t--;)
    {
        memset(check,true,sizeof(check));
        for (int i = 0;i < k; i++)
        {
            scanf("%d",&product);
            for (int j = 0; j < count; j++)
            {
                if (check[j])
                {
                    bool flag = false;
                    for (int l = 0; l < 3; l++)
                    {
                        if (product == data[j][l] ) flag = true;
                    }
                    if (product == 1) flag = true;
                    int pp = 1;
                    for (int l = 0; l < 3; l++)
                    {
                        pp = pp * data[j][l];
                    }
                    if (pp == product) flag = true;
                    for (int l = 0; l < 3 ; l++)
                    {
                        if (pp / data[j][l] == product) flag = true;
                    }
                    if (!flag) check[j] = false;

                }
            }
        }
        for (int i = 0; i <count; i++)
        {
            if (check[i])
            {
                printf("%d%d%d\n",data[i][0],data[i][1],data[i][2]);
                break;

            }
        }
    }

}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define L 1000000

using namespace std;



int main()
{
    int t, cas, n, i, j, k;
    char *name;
    int y, length, count;

    name = (char*)malloc(sizeof(char)*L);

    scanf("%d", &t);

    cas = 0;
    while(t--)
    {
        cas++;
        y=0;

        scanf("%s%d", name, &n);

        for(length=0;name[length]!='\0';length++);

        for(i=0;i<(length-n+1);i++)
        {
            for(j=(i+n-1);j<length;j++)
            {
                count = 0;
                for(k=i;k<=j;k++)
                {
                    if( (name[k] != 'a') && (name[k] != 'e') && (name[k] != 'i') && (name[k] != 'o') && (name[k] != 'u') )
                    {
                        count++;
                    }
                    else
                    {
                        count = 0;
                    }

                    if(count >=n )
                    {
                        y++;
                        break;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", cas, y);
    }

    return 0;
}

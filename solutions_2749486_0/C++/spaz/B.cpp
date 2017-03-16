#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int t, cas, i, j, k, i1;
    int x,y;
    int xlen, ylen;
    bool toggle;

    char EW;
    char NS;
    char* str;
    char* str2;

    str = (char*)malloc(sizeof(char)*200);
    str2 = (char*)malloc(sizeof(char)*200);

    scanf("%d", &t);

    cas = 0;
    while(t--)
    {
        toggle = false;
        cas++;
        scanf("%d%d", &x, &y);
        i=0;

        if(x<0)
        {
            EW = 'W';
            xlen = 0;
            i1 = 0;
            i = 0;
            while(xlen > x)
            {
                str[i] = 'W';
                i1++;
                i++;
                xlen -= i1;
            }
            EW = 'E';
            j=0;
            if( xlen != x)
            {
                for(j=0; x!= xlen ; j++)
                {
                    str[i+j] = 'W';
                    j++;
                    i1++;
                    str[i+j] = 'E';
                    xlen++;
                    i1++;

                }
            }
            str[i+j] = '\0';
        }
        else
        {
            EW = 'E';
            xlen = 0;
            i = 0;
            i1 = 0;
            while(xlen < x)
            {
                str[i] = 'E';
                i++;
                i1++;
                xlen += i1;
            }
            EW = 'W';
            j=0;
            if( xlen != x)
            {
                for(j=0; x!= xlen ; j++)
                {
                    str[i+j] = 'E';
                    j++;
                    i1++;
                    str[i+j] = 'W';
                    xlen--;
                    i1++;

                }
            }
            str[i+j] = '\0';
        }

        if(y<0)
        {
            NS = 'S';
            ylen = 0;
            j = 0;
            while(ylen > y)
            {
                str2[j] = 'S';
                i1++;
                j++;
                ylen -= i1;
            }
            NS = 'N';
            k=0;
            if( ylen != y)
            {
                for(k=0; ylen!=y ; k++)
                {
                    str2[j+k] = 'S';
                    k++;
                    str2[j+k] = 'N';
                    ylen++;
                }
            }
            str2[j+k] = '\0';
        }
        else
        {
            NS = 'N';
            ylen = 0;
            j = 0;
            while(ylen < y)
            {
                str2[j] = 'N';
                i1++;
                j++;
                ylen +=i1;
            }
            NS = 'S';
            k=0;
            if( ylen != y)
            {
                for(k=0; ylen!=y ; k++)
                {
                    str2[j+k] = 'N';
                    k++;
                    str2[j+k] = 'S';
                    ylen--;
                }
            }
            str2[k+j] = '\0';
        }



       /* for(i=0;i<xlen;i++)
        {
            str[i] = EW;
            if(EW == 'E')
                EW = 'W';
            else
                EW = 'E';
        }

        for(j=0;j<ylen;j++)
        {
            str[i+j] = NS;
            if(NS == 'N')
                NS = 'S';
            else
                NS = 'N';
        }

        str[i+j] = '\0';

        */

        printf("Case #%d: %s%s\n", cas, str, str2);
    }

    return 0;
}

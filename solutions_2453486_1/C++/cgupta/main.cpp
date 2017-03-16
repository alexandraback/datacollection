#include <iostream>
#include <cstdio>
using namespace std;

char a[4][4];

int main()
{
    int t,i,j,cx,co,nc,comp,k;

    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&t);
    for(k=1;k<=t;++k)
    {
        for(i=0; i<4; ++i)
        {
            scanf("%s",&a[i]);
            //printf("%s\n",a[i]);
        }
        nc=comp=0;

        // check for rows
        for(i=0; i<4; ++i)
        {
            cx=co=0;
            for(j=0; j<4; ++j)
            {
                if(a[i][j]=='T')
                {
                    cx++;
                    co++;
                }
                else if(a[i][j]=='X') cx++;
                else if(a[i][j]=='O') co++;
                else
                {
                    nc=1;
                    break;
                }
            }
            if(cx==4)
            {
                printf("Case #%d: X won\n",k);
                comp=1;
                break;
            }
            else if(co==4)
            {
                printf("Case #%d: O won\n",k);
                comp=1;
                break;
            }
        }
        //check for coloumns

        if(comp==0)
        {
            for(j=0; j<4; ++j)
            {
                cx=co=0;
                for(i=0; i<4; ++i)
                {
                    if(a[i][j]=='T')
                    {
                        cx++;
                        co++;
                    }
                    else if(a[i][j]=='X') cx++;
                    else if(a[i][j]=='O') co++;
                    else
                    {
                        nc=1;
                        break;
                    }
                }
                if(cx==4)
                {
                    printf("Case #%d: X won\n",k);
                    comp=1;
                    break;
                }
                else if(co==4)
                {
                    printf("Case #%d: O won\n",k);
                    comp=1;
                    break;
                }
            }
        }
        //check for diagonal

        if(comp==0)
        {
            cx=co=0;
            for(i=0; i<4; ++i)
            {
                if(a[i][i]=='T')
                {
                    cx++;
                    co++;
                }
                else if(a[i][i]=='X') cx++;
                else if(a[i][i]=='O') co++;
                else
                {
                    nc=1;
                    break;
                }
            }
            if(cx==4)
            {
                printf("Case #%d: X won\n",k);
                comp=1;
            }
            else if(co==4)
            {
                printf("Case #%d: O won\n",k);
                comp=1;
            }
        }
        // chack for diagonal 2

        if(comp==0)
        {
            cx=co=0;
            for(i=0; i<4; ++i)
            {
                if(a[i][3-i]=='T')
                {
                    cx++;
                    co++;
                }
                else if(a[i][3-i]=='X') cx++;
                else if(a[i][3-i]=='O') co++;
                else
                {
                    nc=1;
                    break;
                }
            }
            if(cx==4)
            {
                printf("Case #%d: X won\n",k);
                comp=1;
            }
            else if(co==4)
            {
                printf("Case #%d: O won\n",k);
                comp=1;
            }
        }
        if(comp==0 && nc==0)
        {
            printf("Case #%d: Draw\n",k);
        }else if(comp==0){
            printf("Case #%d: Game has not completed\n",k);
        }
    }
    return 0;
}

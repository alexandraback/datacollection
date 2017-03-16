#include<cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    int casno=0;
    while(T--)
    {
        casno++;
        char g[4][5];
        for(int i=0; i<4; i++)
            scanf("%s",g[i]);
        int total=0;
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                if(g[i][j]!='.')
                    total++;
        bool awin=0;
        bool bwin=0;
        for(int i=0; i<4; i++)
        {
            int a=0,b=0;
            for(int j=0; j<4; j++)
            {
                if(g[i][j]=='X')
                    a++;
                if(g[i][j]=='O')
                    b++;
                if(g[i][j]=='T')
                    a++,b++;
            }
            if(a==4)
            {
                awin=1;
                break;
            }
            if(b==4)
            {
                bwin=1;
                break;
            }
        }
        for(int i=0; i<4; i++)
        {
            int a=0,b=0;
            for(int j=0; j<4; j++)
            {
                if(g[j][i]=='X')
                    a++;
                if(g[j][i]=='O')
                    b++;
                if(g[j][i]=='T')
                    a++,b++;
            }
            if(a==4)
            {
                awin=1;
                break;
            }
            if(b==4)
            {
                bwin=1;
                break;
            }
        }
        int a=0,b=0;
        for(int i=0; i<4; i++)
        {

            if(g[i][i]=='X')
                a++;
            if(g[i][i]=='O')
                b++;
            if(g[i][i]=='T')
                a++,b++;
            if(a==4)
            {
                awin=1;
                break;
            }
            if(b==4)
            {
                bwin=1;
                break;
            }
        }
        a=0,b=0;
        for(int i=0; i<4; i++)
        {
            if(g[i][3-i]=='X')
                a++;
            if(g[i][3-i]=='O')
                b++;
            if(g[i][3-i]=='T')
                a++,b++;
            if(a==4)
            {
                awin=1;
                break;
            }
            if(b==4)
            {
                bwin=1;
                break;
            }
        }
        printf("Case #%d: ",casno);
        if(awin)
            printf("X won\n");
        else if(bwin)
            printf("O won\n");
        else
        {
            if(total!=16)
                printf("Game has not completed\n");
            else
                printf("Draw\n");
        }
    }
    return 0;
}

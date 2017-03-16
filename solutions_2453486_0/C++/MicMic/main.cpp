#include <iostream>
#include <cstdio>
using namespace std;
char map[6][6];
int judge(bool flag,int cntx,int cnto)
{
    if(flag)
    {
        if(cntx==3)
        {
            printf("X won\n");
            return 1;
        }
        if(cnto==3)
        {
            printf("O won\n");
            return 2;
        }
    }
    else
    {
        if(cntx==4)
        {
            printf("X won\n");
            return 1;
        }
        if(cnto==4)
        {
            printf("O won\n");
            return 2;
        }
    }
    return 0;
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int z=1; z<=cas; z++)
    {
        printf("Case #%d: ",z);
        bool covered=1;
        int res=0;
        int cntx,cnto;
        bool flag;
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
            {
                scanf(" %c",&map[i][j]);
                if(map[i][j]=='.')covered=0;
            }

        for(int i=0; i<4; i++) //检查每一行
        {
            flag=0;
            cntx=cnto=0;
            for(int j=0; j<4; j++)
            {
                if(map[i][j]=='X')
                    cntx++;
                if(map[i][j]=='O')
                    cnto++;
                if(map[i][j]=='T')
                    flag=1;
            }
            res=judge(flag,cntx,cnto);
            if(res)break;
        }
        if(res)continue;
        for(int j=0; j<4; j++)
        {
            flag=0;
            cntx=cnto=0;
            for(int i=0; i<4; i++)
            {
                if(map[i][j]=='X')
                    cntx++;
                if(map[i][j]=='O')
                    cnto++;
                if(map[i][j]=='T')
                    flag=1;
            }
            res=judge(flag,cntx,cnto);
            if(res)break;
        }
        if(res)continue;
        flag=0;
        cntx=cnto=0;
        for(int i=0; i<4; i++)
        {
            if(map[i][i]=='X')
                cntx++;
            if(map[i][i]=='O')
                cnto++;
            if(map[i][i]=='T')
                flag=1;
        }
        res=judge(flag,cntx,cnto);
        if(res)continue;
        flag=0;
        cntx=cnto=0;
        for(int i=0; i<4; i++)
        {
            if(map[i][3-i]=='X')
                cntx++;
            if(map[i][3-i]=='O')
                cnto++;
            if(map[i][3-i]=='T')
                flag=1;
        }
        res=judge(flag,cntx,cnto);
        if(!res)
        {
            if(covered)printf("Draw\n");
            else printf("Game has not completed\n");
        }
    }
}

#include <cstdio>
#include <cstring>
int main()
{
    freopen("a.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    char s[10][10];
    for(int t=1; t<=T; t++)
    {
        for(int i=0; i<4; i++)
        scanf("%s",s[i]);
        bool end = 1;
        for(int i=0; end&&i<4; i++)
        for(int j=0; j<4; j++)
        if(s[i][j]=='.')
        {
            end = 0;
            break;
        }
        printf("Case #%d: ",t);
        bool winX,winO;
        for(int i=0; i<4; i++)
        {
            winX = 1;
            for(int j=0; j<4; j++)
            if(s[i][j]!='T'&&s[i][j]!='X')
            {
                winX = 0;
                break;
            }
            if(winX) break;
            winX = 1;
            for(int j=0; j<4; j++)
            if(s[j][i]!='T'&&s[j][i]!='X')
            {
                winX = 0;
                break;
            }
            if(winX) break;
        }
        if(!winX)
        {
            winX = 1;
            for(int i=0; i<4; i++)
            if(s[i][i]!='T'&&s[i][i]!='X')
            {
                winX = 0;
                break;
            }
            if(!winX)
            {
                winX = 1;
                for(int i=0; i<4; i++)
                if(s[i][3-i]!='T'&&s[i][3-i]!='X')
                {
                    winX = 0;
                    break;
                }
            }
        }
        if(winX)
        {
            puts("X won");
            continue;
        }
        for(int i=0; i<4; i++)
        {
            winO = 1;
            for(int j=0; j<4; j++)
            if(s[i][j]!='T'&&s[i][j]!='O')
            {
                winO = 0;
                break;
            }
            if(winO) break;
            winO = 1;
            for(int j=0; j<4; j++)
            if(s[j][i]!='T'&&s[j][i]!='O')
            {
                winO = 0;
                break;
            }
            if(winO) break;
        }
        if(!winO)
        {
            winO = 1;
            for(int i=0; i<4; i++)
            if(s[i][i]!='T'&&s[i][i]!='O')
            {
                winO = 0;
                break;
            }
            if(!winO)
            {
                winO = 1;
                for(int i=0; i<4; i++)
                if(s[i][3-i]!='T'&&s[i][3-i]!='O')
                {
                    winO = 0;
                    break;
                }
            }
        }
        if(winO)
        {
            puts("O won");
            continue;
        }
        if(end) puts("Draw");
        else puts("Game has not completed");
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[10][10];
int check(char c)
{
    for(int i = 0; i < 4; i++)
    {
        int ok = 1;
        for(int j = 0; j < 4; j++)
            if(s[i][j]!='T' && s[i][j]!=c)
                ok = 0;
        if(ok)return 1;
    }
    for(int i = 0; i < 4; i++)
    {
        int ok = 1;
        for(int j = 0; j < 4; j++)
            if(s[j][i]!='T' && s[j][i]!=c)
                ok = 0;
        if(ok)return 1;
    }
    int ok = 1;
    for(int i = 0; i < 4; i++)
        if(s[i][i]!='T' && s[i][i]!=c)
            ok = 0;
    if(ok)return 1;
    ok = 1;
    for(int i = 0; i < 4; i++)
        if(s[i][3-i]!='T' && s[i][3-i]!=c)
            ok = 0;
    if(ok)return 1;
    return 0;
}
int end()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(s[i][j]=='.')return 0;
    return 1;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 0; i < 4; i++)
            scanf("%s",s[i]);
        int ret = 0;
        if(check('X'))ret = 1;
        else if(check('O'))ret = 2;
        else if(end())ret = 3;

        printf("Case #%d: ",++cas);
        if(ret==0)puts("Game has not completed");
        else if(ret==1)puts("X won");
        else if(ret==2)puts("O won");
        else puts("Draw");
    }

    return 0;
}

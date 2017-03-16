#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[10][10];
int T,ans,x,o,t;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        ans=0;
        for(int i=0; i<4; i++)
        {
            scanf("%s",s[i]);
            for(int j=0; j<4; j++)
                if(s[i][j]=='.')ans=3;
        }
        for(int i=0; i<4; i++)
        {
            x=o=t=0;
            for(int j=0; j<4; j++)
                if(s[i][j]=='X')x++;
                else if(s[i][j]=='O')o++;
                else if(s[i][j]=='T')t++;
            if(t<2)
            {
                if(x+t==4)ans=1;
                else if(o+t==4)ans=2;
            }
        }
        x=o=t=0;
        for(int i=0; i<4; i++)
        {
            if(s[i][i]=='X')x++;
            else if(s[i][i]=='O')o++;
            else if(s[i][i]=='T')t++;
        }
        if(t<2)
        {
            if(x+t==4)ans=1;
            else if(o+t==4)ans=2;
        }
        x=o=t=0;
        for(int i=0; i<4; i++)
        {
            if(s[i][3-i]=='X')x++;
            else if(s[i][3-i]=='O')o++;
            else if(s[i][3-i]=='T')t++;
        }
        if(t<2)
        {
            if(x+t==4)ans=1;
            else if(o+t==4)ans=2;
        }
        for(int j=0; j<4; j++)
        {
            x=o=t=0;
            for(int i=0; i<4; i++)
                if(s[i][j]=='X')x++;
                else if(s[i][j]=='O')o++;
                else if(s[i][j]=='T')t++;
            if(t<2)
            {
                if(x+t==4)ans=1;
                else if(o+t==4)ans=2;
            }
        }
        if(ans==0)printf("Case #%d: Draw\n",cas);
        else if(ans==1)printf("Case #%d: X won\n",cas);
        else if(ans==2)printf("Case #%d: O won\n",cas);
        else printf("Case #%d: Game has not completed\n",cas);
    }
    return 0;
}

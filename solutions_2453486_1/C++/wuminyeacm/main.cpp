#include <stdio.h>
#include <string.h>
char map[5][5];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
        int cnt=0,ans=-1;
        for (int i=0;i<4;++i)
          {
              scanf("%s",map[i]);
              for (int j=0;j<4;++j) if (map[i][j]!='.') ++cnt;
          }
        bool flagr=false,flagc=false,x1=false,x2=false;
        for (int i=0;i<4;++i)
        {
            int j=0;
            while (map[i][j]=='.' && j<4) ++j;
            int on=0,xn=0,tn=0,t=j;
            for (;j<4 && map[i][j]!='.';++j)
            {
                char p=map[i][j];
                if (p=='O') ++on;
                if (p=='X') ++xn;
                if (p=='T') ++tn;
            }
            if (t==0 && j==4) flagr=true;
            if (max(on,xn)+tn==4)
            {
                if (max(on,xn)==on)
                {
                    ans=1;break;
                } else {ans=2;break;}
            }
        }

        for (int i=0;i<4 && ans==-1;++i)
        {
            int j=0;
            while (map[j][i]=='.' && j<4) ++j;
            int on=0,xn=0,tn=0,t=j;
            for (;j<4 && map[j][i]!='.';++j)
            {
                char p=map[j][i];
                if (p=='O') ++on;
                if (p=='X') ++xn;
                if (p=='T') ++tn;
            }
            if (t==0 && j==4) flagc=true;
            if (max(on,xn)+tn==4)
            {
                if (max(on,xn)==on)
                {
                    ans=1;break;
                } else {ans=2;break;}
            }
        }
        if (ans==-1)
        {
            int j=0;
            while (map[j][j]=='.' && j<4) ++j;
            int on=0,xn=0,tn=0,t=j;
            for (;j<4 && map[j][j]!='.';++j)
            {
                char p=map[j][j];
                if (p=='O') ++on;
                if (p=='X') ++xn;
                if (p=='T') ++tn;
            }
            if (t==0 && j==4) x1=true;
            if (max(on,xn)+tn==4)
            {
                if (max(on,xn)==on)
                {
                    ans=1;
                } else {ans=2;}
            }
        }
        if (ans==-1)
        {
            int j=0;
            while (map[j][3-j]=='.' && j<4) ++j;
            int on=0,xn=0,tn=0,t=j;
            for (;j<4 && map[j][3-j]!='.';++j)
            {
                char p=map[j][3-j];
                if (p=='O') ++on;
                if (p=='X') ++xn;
                if (p=='T') ++tn;
            }
            if (t==0 && j==4) x2=true;
            if (max(on,xn)+tn==4)
            {
                if (max(on,xn)==on)
                {
                    ans=1;
                } else {ans=2;}
            }
        }
        printf("Case #%d: ",++cas);
        if (ans!=-1)
        {
            if (ans==1) printf("O won\n");
            if (ans==2) printf("X won\n");
        } else
        {
            if (cnt<16) printf("Game has not completed\n");
             else printf("Draw\n");
        }
    }

}

#include<cstdio>

#define MAXX 5

char buf[MAXX][MAXX];

short T,t;
int n,a,b,c,ans;

inline bool calr(int r,char ch)
{
    static int i,a,t;
    for(i=a=t=0;i<4;++i)
    {
        t+=(buf[r][i]=='T');
        a+=(buf[r][i]==ch);
    }
    if(t+a==4)
        return t<=1;
    return false;
}

inline bool calc(int c,char ch)
{
    static int i,a,t;
    for(i=a=t=0;i<4;++i)
    {
        t+=(buf[i][c]=='T');
        a+=(buf[i][c]==ch);
    }
    if(t+a==4)
        return t<=1;
    return false;
}

inline bool cald(char ch)
{
    static int i,a,t;
    for(i=a=t=0;i<4;++i)
    {
        t+=(buf[i][i]=='T');
        a+=(buf[i][i]==ch);
    }
    if(t+a==4)
        return t<=1;
    return false;
}

inline bool calx(char ch)
{
    static int i,a,t;
    for(i=a=t=0;i<4;++i)
    {
        t+=(buf[3-i][i]=='T');
        a+=(buf[3-i][i]==ch);
    }
    if(t+a==4)
        return t<=1;
    return false;
}

int i,j;

int main()
{
    scanf("%hd",&T);
    for(t=1;t<=T;++t)
    {
        printf("Case #%hd: ",t);
        for(i=0;i<4;++i)
            scanf("%s",buf[i]);
        ans=0;
        for(i=0;i<4;++i)
        {
            if(calr(i,'X') || calc(i,'X'))
                ans|=1;
            if(calr(i,'O') || calc(i,'O'))
                ans|=2;
        }
        if(cald('X') || calx('X'))
            ans|=1;
        if(cald('O') || calx('O'))
            ans|=2;
        for(i=c=0;i<4;++i)
            for(j=0;j<4;++j)
                if(buf[i][j]=='.')
                    c=1;
        switch(ans)
        {
            case 0:
                if(c)
                    puts("Game has not completed");
                else
                    puts("Draw");
                break;
            case 1:
                puts("X won");
                break;
            case 2:
                puts("O won");
                break;
            case 3:
                puts("Draw");
                break;
        }
    }
    return 0;
}

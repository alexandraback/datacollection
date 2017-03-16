#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#define MAXN 64
#define INF 1<<30
///
using namespace std;

char check(char a,char b,char c,char d)
{
    if(a==b&&b==c&&c==d&&d!='.'&&d!='T') return d;
    if(a==b&&b==c&&c!=d&&c!='.'&&d=='T') return c;
    if(a==b&&b==d&&c!=d&&d!='.'&&c=='T') return d;
    if(a==c&&c==d&&b!=d&&d!='.'&&b=='T') return d;
    if(b==c&&c==d&&a!=d&&d!='.'&&a=='T') return d;
    return 0;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    char s[5][5];
    for(int t=1; t<=cases; t++)
    {
        for(int i=0; i<4; i++)
        {
            scanf("%s",s[i]);
        }
        printf("Case #%d: ",t);
        char r[4];
        bool flag1=false;
        for(int i=0; i<4; i++)
        {
            r[i]=check(s[i][0],s[i][1],s[i][2],s[i][3]);
            if(r[i])
            {
                if(r[i]=='X')
                {
                    printf("X won\n");
                }
                else
                {
                    printf("O won\n");
                }
                flag1=true;
                break;
            }
        }
        if(flag1) continue;
        char c[4];
        bool flag2=false;
        for(int i=0; i<4; i++)
        {
            c[i]=check(s[0][i],s[1][i],s[2][i],s[3][i]);
            if(c[i])
            {
                if(c[i]=='X')
                {
                    printf("X won\n");
                }
                else
                {
                    printf("O won\n");
                }
                flag2=true;
                break;
            }
        }
        if(flag2) continue;
        char d[2];
        bool flag3=false;
        d[1]=check(s[0][0],s[1][1],s[2][2],s[3][3]);
        d[2]=check(s[0][3],s[1][2],s[2][1],s[3][0]);
        if(d[1])
        {
            if(d[1]=='X')
            {
                printf("X won\n");
            }
            else
            {
                printf("O won\n");
            }
            flag3=true;
        }
        if(flag3) continue;
        if(d[2])
        {
            if(d[2]=='X')
            {
                printf("X won\n");
            }
            else
            {
                printf("O won\n");
            }
            flag3=true;
        }
        if(flag3) continue;
        bool flag=true;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(s[i][j]=='.')
                {
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag)
        {
            printf("Draw\n");
        }
        else
        {
            printf("Game has not completed\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

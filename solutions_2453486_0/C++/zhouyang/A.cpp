#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[10][10];
int t,flag;
bool visited[10][10];
char in[]= {'.','O','X','T'};
int max(int a,int b)
{
    return a>b?a:b;
}
bool judge(int x,int y)
{
    return (x>=0&&x<4&&y>=0&&y<4&&!visited[x][y]);
}
int c[5][5],w[5][5],x[5],y[5];
int main ()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    char ch,ch2;
    int cnt;
    scanf("%d",&t);
    getchar();
    for(int l=1; l<=t; l++)
    {
        memset(w,0,sizeof(w));
        memset(c,0,sizeof(c));
        memset(map,'.',sizeof(map));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        cnt=0;
        flag=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='.')
                {
                    w[i][0]++;
                    cnt++;
                }
                if(map[i][j]=='O')
                    w[i][1]++;
                if(map[i][j]=='X')
                    w[i][2]++;
                if(map[i][j]=='T')
                    w[i][3]++;
            }
        }
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(map[j][i]=='.')
                    c[i][0]++;
                if(map[j][i]=='O')
                    c[i][1]++;
                if(map[j][i]=='X')
                    c[i][2]++;
                if(map[j][i]=='T')
                    c[i][3]++;
            }
        }
        for(int i=0; i<4; i++)
        {
            if(map[i][i]=='.')
                x[0]++;
            if(map[i][i]=='O')
                x[1]++;
            if(map[i][i]=='X')
                x[2]++;
            if(map[i][i]=='T')
                x[3]++;
        }
        for(int i=0; i<4; i++)
        {
            if(map[i][3-i]=='.')
                y[0]++;
            if(map[i][3-i]=='O')
                y[1]++;
            if(map[i][3-i]=='X')
                y[2]++;
            if(map[i][3-i]=='T')
                y[3]++;
        }

        if((max(x[1],x[2])+x[3])==4&&!flag)
        {
            flag=1;
            if(max(x[1],x[2])==x[1])
                printf("O won\n");
            else if(max(x[1],x[2])==x[2])
                printf("X won\n");
        }
        if((max(y[1],y[2])+y[3])==4&&!flag)
        {
            flag=1;
            if(max(y[1],y[2])==y[1])
                printf("Case #%d: O won\n",l);
            else if(max(y[1],y[2])==y[2])
                 printf("Case #%d: X won\n",l);
        }

        for(int i=0; i<4; i++)
        {
            if((max(c[i][1],c[i][2])+c[i][3])==4&&!flag)
            {
                flag=1;
                if(max(c[i][1],c[i][2])==c[i][1])

                     printf("Case #%d: O won\n",l);
                else if(max(c[i][1],c[i][2])==c[i][2])

                     printf("Case #%d: X won\n",l);
            }
            if((max(w[i][1],w[i][2])+w[i][3])==4&&!flag)
            {
                flag=1;
                if(max(w[i][1],w[i][2])==w[i][1])
                    printf("Case #%d: O won\n",l);
                else if(max(w[i][1],w[i][2])==w[i][2])
                     printf("Case #%d: X won\n",l);
            }
        }
        if(cnt==0&&flag==0)
             printf("Case #%d: Draw\n",l);
        else if(cnt!=0&&flag==0)
            printf("Case #%d: Game has not completed\n",l);
    }
}

#include <cstdio>
#include <algorithm>
using namespace std;
void funct(int t)
{
    printf("Case #%d: ",t);
    bool x=0;
    char s[5][5];
    int u[5][5][2]={0},l[5][5][2]={0},ul[5][5][2]={0},ur[5][5][2]={0};
    for(int j=1;j<5;j++)
        scanf(" %s",s[j]+1);
    for(int j=1;j<5;j++)
    {
        for(int k=1;k<5;k++)
        {
            if(s[j][k]=='.')
            {
                x=1;
                continue;
            }
            if(s[j][k]!='O')
            {
                u[j][k][0]=u[j-1][k][0]+1;
                l[j][k][0]=l[j][k-1][0]+1;
                ul[j][k][0]=ul[j-1][k-1][0]+1;
                ur[j][k][0]=ur[j-1][k+1][0]+1;
            }
            if(s[j][k]!='X')
            {
                u[j][k][1]=u[j-1][k][1]+1;
                l[j][k][1]=l[j][k-1][1]+1;
                ul[j][k][1]=ul[j-1][k-1][1]+1;
                ur[j][k][1]=ur[j-1][k+1][1]+1;
            }

        }
    }
    for(int j=1;j<5;j++)
    {
        for(int k=1;k<5;k++)
        {
            if(u[j][k][0]==4||l[j][k][0]==4||ul[j][k][0]==4||ur[j][k][0]==4)
            {
                printf("X won\n");
                return;
            }
            if(u[j][k][1]==4||l[j][k][1]==4||ul[j][k][1]==4||ur[j][k][1]==4)
            {
                printf("O won\n");
                return;
            }
        }
    }
    if(x)
        printf("Game has not completed\n");
    else
        printf("Draw\n");
}
int main()
{
    freopen("Tic.in","r",stdin);
    freopen("ou.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        funct(i);
}

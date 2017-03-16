#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,k,flag;
char s[6][6];
int map[6][6];
bool check_x()
{
    int i,j;
    for(i=1;i<=4;i++)
    {
        if(map[i][0]+map[i][1]+map[i][2]+map[i][3]>=33)
        return true;
    }
    for(i=0;i<4;i++)
    {
        if(map[1][i]+map[2][i]+map[3][i]+map[4][i]>=33)
        return true;
    }
    if(map[1][0]+map[2][1]+map[3][2]+map[4][3]>=33)
    return true;
    if(map[1][3]+map[2][2]+map[3][1]+map[4][0]>=33)
    return true;
    return false;
}
bool check_o()
{
    int i,j;
    for(i=1;i<=4;i++)
    {
        if(map[i][0]+map[i][1]+map[i][2]+map[i][3]>=8&&map[i][0]+map[i][1]+map[i][2]+map[i][3]<=9)
        return true;
    }
    for(i=0;i<4;i++)
    {
        if(map[1][i]+map[2][i]+map[3][i]+map[4][i]>=8&&map[1][i]+map[2][i]+map[3][i]+map[4][i]<=9)
        return true;
    }
    if(map[1][0]+map[2][1]+map[3][2]+map[4][3]>=8&&map[1][0]+map[2][1]+map[3][2]+map[4][3]<=9)
    return true;
    if(map[1][3]+map[2][2]+map[3][1]+map[4][0]>=8&&map[1][3]+map[2][2]+map[3][1]+map[4][0]<=9)
    return true;
    return false;
}
int main()
{
    //freopen("A.in","r",stdin);
    //freopen("1.txt","w",stdout);
    k=1;
    scanf("%d",&n);
    while(n--)
    {
        int i,j;
        flag=0;
        for(i=1;i<=4;i++)
       {
           scanf("%s",s[i]);
           for(j=0;j<4;j++)
           {
               if(s[i][j]=='X')
               map[i][j]=10;
               if(s[i][j]=='O')
               map[i][j]=2;
               if(s[i][j]=='T')
               map[i][j]=3;
               if(s[i][j]=='.')
               {
                   flag=1;
                   map[i][j]=0;
               }
           }
       }
       if(check_x())
       {
           printf("Case #%d: X won\n",k++);
       }
       else if(check_o())
       {
           printf("Case #%d: O won\n",k++);
       }
       else if(flag==0)
       {
           printf("Case #%d: Draw\n",k++);
       }
       else if(flag==1)
       {
           printf("Case #%d: Game has not completed\n",k++);
       }
    }
    return 0;
}

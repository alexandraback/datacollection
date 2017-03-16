#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int Max=10;
char map[Max][Max];
int num[4][2],num1[4][2];
int flag;
int main()
{
    //freopen("11.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int i,j,k,l,n,m,T;
    scanf("%d",&n);
    getchar();
    for(T=1;T<=n;T++)
    {
        flag=0;
        memset(num,0,sizeof(num));
        memset(num1,0,sizeof(num1));
        memset(map,0,sizeof(map));
       for(i=0;i<4;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<4;j++)
            {
                if(map[i][j]=='.')
                flag=1;
            }
        }
        int flag1=1,flag2=1;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                 if(map[i][j]=='X'||map[i][j]=='T')
                    num[i][0]++;
                 if(map[i][j]=='O'||map[i][j]=='T')
                    num[i][1]++;
                 }
            }
            for(i=0;i<4;i++)
            {
                 for(j=0;j<4;j++)
                {
                 if(map[j][i]=='X'||map[j][i]=='T')
                    num1[i][0]++;
                 if(map[j][i]=='O'||map[j][i]=='T')
                    num1[i][1]++;
                 }
            }
            for(i=0;i<4;i++)
            {
                if(map[i][i]!='X'&&map[i][i]!='T')
                    flag1=0;
                if(map[i][i]!='O'&&map[i][i]!='T')
                    flag2=0;
            }
            int flag3=1,flag4=1;
            for(i=3;i>=0;i--)
            {
                if(map[3-i][i]!='X'&&map[3-i][i]!='T')
                    flag3=0;
                if(map[3-i][i]!='O'&&map[3-i][i]!='T')
                    flag4=0;
            }
            int ans1=0,ans2=0;
            for(i=0;i<4;i++)
            {
                if(num[i][0]==4||num1[i][0]==4)
                    ans1=1;
                if(num[i][1]==4||num1[i][1]==4)
                    ans2=1;
            }
            if(flag1||flag3)
                ans1=1;
            if(flag2||flag4)
                ans2=1;
        printf("Case #%d: ",T);
         if(ans2)
            printf("O won\n");
         else
         {

             if(ans1)
              printf("X won\n");
             else
            {
                if(flag)
                    printf("Game has not completed\n");
                else
                    printf("Draw\n");
            }
         }
    }
    return 0;
}

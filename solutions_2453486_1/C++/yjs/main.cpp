#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
int t;
char mp[5][5];
bool solve(char target)
{
       int i,j;
       for(i=1;i<=4;i++)
       {
              for(j=0;j<4;j++)
                     if(mp[i][j]!=target&&mp[i][j]!='T')
                            break;
              if(j==4)
                     return true;
              for(j=1;j<=4;j++)
                     if(mp[j][i-1]!=target&&mp[j][i-1]!='T')
                            break;
              if(j==5)
                     return true;
       }
       for(i=1;i<=4;i++)
              if(mp[i][i-1]!=target&&mp[i][i-1]!='T')
                     break;
       if(i==5)return true;
       for(i=1;i<=4;i++)
              if(mp[i][4-i]!=target&&mp[i][4-i]!='T')
                     break;
       if(i==5)return true;
       return false;
}
int main()
{
       //freopen("")
       freopen("out.out","w",stdout);
       scanf("%d",&t);
       int j,k;
       for(int i=1;i<=t;i++)
       {
              for(j=1;j<=4;j++)
                   scanf("%s",mp[j]);
              printf("Case #%d: ",i);
              if(solve('X'))
                     printf("X won");
              else if(solve('O'))
                     printf("O won");
              else
              {
                     for(k=1;k<=4;k++)
                     {
                            for(j=0;j<4;j++)
                                   if(mp[k][j]=='.')
                                          break;
                            if(j!=4)
                                   break;
                     }
                     if(k!=5)
                            printf("Game has not completed");
                     else
                            printf("Draw");

              }
              printf("\n");

       }
    return 0;
}

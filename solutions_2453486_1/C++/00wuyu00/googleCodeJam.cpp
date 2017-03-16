#include<iostream>
#include<stdio.h>
using namespace std;
char a[5][5];
int find(char c)
{
int num,tnum=0;
for(int i=1;i<=4;i++)
{
    num=0;tnum=0;
  for(int j=1;j<=4;j++)
    if(a[i][j]==c)
    num++;
  else if(a[i][j]=='T')
    tnum++;
  if(num==4||(num==3&&tnum==1))
    return 1;
}
tnum=0;
for(int j=1;j<=4;j++)
{
    num=0;tnum=0;
    for(int i=1;i<=4;i++)
        if(a[i][j]==c)
        num++;
      else if(a[i][j]=='T')
        tnum++;
    if(num==4||(num==3&&tnum==1))
    return 1;

}
tnum=0;num=0;
for(int i=1;i<=4;i++)
{
if(a[i][i]==c)
        num++;
     else if(a[i][i]=='T')
        tnum++;
}
if(num==4||(num==3&&tnum==1))
    return 1;
tnum=0;num=0;
for(int i=1;i<=4;i++)
{
    if(a[i][5-i]==c)
        num++;
     else if(a[i][5-i]=='T')
        tnum++;
}
if(num==4||(num==3&&tnum==1))
    return 1;
    return 0;

}
int main()
{
   freopen("A-large.in","r",stdin);
   freopen("output.out","w",stdout);
    int n,m,i,t;

    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
      for(int i=1;i<=4;i++)
      {
          getchar();
        for(int j=1;j<=4;j++)
          scanf("%c",&a[i][j]);

      }
      int flag=0;
      int zhishi=1;
      for(int i=1;i<=4;i++)

        for(int j=1;j<=4;j++)
          if(a[i][j]=='.')zhishi=0;
      if(!zhishi) flag=-1;
      if (find('X')==1)
        flag=1;
      if (find('O'))
        flag=2;
        printf("Case #%d: ",k+1);
      if(flag==2)
        printf("O won\n");
      if(flag==1)
        printf("X won\n");
      if(flag==0)
        printf("Draw\n");
      if(flag==-1)
        printf("Game has not completed\n");
        getchar();

    }
return 0;
}

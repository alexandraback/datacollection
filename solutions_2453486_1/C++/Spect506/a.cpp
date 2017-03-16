#include<cstdio>
char str[5][5];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tt,test,i,j,em,end;
    scanf("%d",&test);
    for(tt=1;tt<=test;tt++)
    {
      gets(str[0]);
      for(i=0;i<4;i++)gets(str[i]);
      printf("Case #%d: ",tt);
      int nx,no,nt;
      em=0;
      end=0;
      for(i=0;i<4;i++)
      {
        nx=0;no=0;nt=0;
        for(j=0;j<4;j++)
        {
          if(str[i][j]=='X')nx++;
          if(str[i][j]=='O')no++;
          if(str[i][j]=='T')nt++;
          if(str[i][j]=='.')em=1;
        }
        if(nt>1)continue;
        if(nx+nt==4)end=1;
        else if(no+nt==4)end=2;
      }
      if(end==1)
      {
        printf("X won\n");
        continue;
      }
      if(end==2)
      {
        printf("O won\n");
        continue;
      }
      for(j=0;j<4;j++)
      {
        nx=0;no=0;nt=0;
        for(i=0;i<4;i++)
        {
          if(str[i][j]=='X')nx++;
          if(str[i][j]=='O')no++;
          if(str[i][j]=='T')nt++;
          if(str[i][j]=='.')em=1;
        }
        if(nt>1)continue;
        if(nx+nt==4)end=1;
        else if(no+nt==4)end=2;
      }
      if(end==1)
      {
        printf("X won\n");
        continue;
      }
      if(end==2)
      {
        printf("O won\n");
        continue;
      }
      nx=0;no=0;nt=0;
      for(i=0;i<4;i++)
      {
        if(str[i][i]=='X')nx++;
        if(str[i][i]=='O')no++;
        if(str[i][i]=='T')nt++;
        if(str[i][i]=='.')em=1;
      }
      if(nt<2)
      {
        if(nx+nt==4)end=1;
        else if(no+nt==4)end=2;
      }
      if(end==1)
      {
        printf("X won\n");
        continue;
      }
      if(end==2)
      {
        printf("O won\n");
        continue;
      }
      nx=0;no=0;nt=0;
      for(i=0;i<4;i++)
      {
        if(str[i][3-i]=='X')nx++;
        if(str[i][3-i]=='O')no++;
        if(str[i][3-i]=='T')nt++;
        if(str[i][3-i]=='.')em=1;
      }
      if(nt<2)
      {
        if(nx+nt==4)end=1;
        else if(no+nt==4)end=2;
      }
      if(end==1)
      {
        printf("X won\n");
        continue;
      }
      if(end==2)
      {
        printf("O won\n");
        continue;
      }
      if(em)printf("Game has not completed\n");
      else printf("Draw\n");
    }
    return 0;
}

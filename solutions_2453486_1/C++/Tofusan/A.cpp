#include <stdio.h>
#include <stdlib.h>

int t;
char A[10][10];
int ans;
int chk(int a,int b,char c)
{
char d=c;
  if(a==0)
  {
   c=d;
   if(c=='T')
   {
    c=A[1][b];
   }
   if(c!='.')
   {
    for(int i=1;i<=3;i++)
    {
     if(A[i][b]!=c&&A[i][b]!='T'){break;}
     else if(i==3)
     {
      if(c=='X'){return 1;}
      else{return 2;}
     }
    }
   }
  }
  if(b==0)
  {
   c=d;
   if(c=='T')
   {
    c=A[a][1];
   }
   if(c!='.')
   {
    for(int i=1;i<=3;i++)
    {
     if(A[a][i]!=c&&A[a][i]!='T'){break;}
     else if(i==3)
     {
      if(c=='X'){return 1;}
      else{return 2;}
     }
    }
   }
  }
  if(a==0&&b==0)
  {
  c=d;
   if(c=='T')
   {
    c=A[1][1];
   }
   if(c!='.')
   {
    for(int i=1;i<=3;i++)
    {
     if(A[i][i]!=c&&A[i][i]!='T'){break;}
     else if(i==3)
     {
      if(c=='X'){return 1;}
      else{return 2;}
     }
    }
   }
  }
   if(a==3&&b==0)
  {
   c=d;
   if(c=='T')
   {
    c=A[2][1];
   }
   if(c!='.')
   {
    for(int i=1;i<=3;i++)
    {
     if(A[3-i][i]!=c&&A[3-i][i]!='T'){break;}
     else if(i==3)
     {
      if(c=='X'){return 1;}
      else{return 2;}
     }
    }
   }
  }
  return 0; 
}
int solve()
{
int cnt=0;
int tmp;
 for(int i=0;i<4;i++)
 {
  //printf("%s\n",A[i]);
  for(int j=0;j<4;j++)
  {
   if(A[i][j]=='.'){cnt++;}
  }
 }
 //printf("cnt %d\n",cnt);
 for(int i=0;i<4;i++)
 {
  for(int j=0;j<4;j++)
  {
   if(A[i][j]=='O'||A[i][j]=='X'||A[i][j]=='T')
   {
   tmp=chk(i,j,A[i][j]);
    if(tmp!=0)
    {
     return tmp;
    }
   }
  }
 }
 if(cnt==0){return 3;}
 return 4;
}
main()
{
 freopen("A-large.in","r",stdin);
 freopen("A-large.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  //if(tests>1){scanf("%s",A[0]);}
  for(int i=0;i<4;i++)
  {
   scanf("%s",A[i]);
  }
  ans=solve();
  printf("Case #%d: ",tests);
  if(ans==1){printf("X won\n");}
  else if(ans==2){printf("O won\n");}
  else if(ans==3){printf("Draw\n");}
  else if(ans==4){printf("Game has not completed\n");}
 }

 return 0;
}

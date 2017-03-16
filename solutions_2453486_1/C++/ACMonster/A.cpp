//program A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int TotalTest,Test=0;
  scanf("%d",&TotalTest);
  char Map[4][4];
  while(TotalTest--)
    {
      printf("Case #%d: ",++Test);
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
          {
            char c;
            while(c=getchar(),c!='.'&&c!='O'&&c!='X'&&c!='T');
            Map[i][j]=c;
          }
      int Ans=0;
      for(int i=0;i<4;i++)
        {
          bool X=true,O=true;
          for(int j=0;j<4;j++)
            if(Map[i][j]=='X')
              O=false;
            else if(Map[i][j]=='O')
              X=false;
            else if(Map[i][j]=='.')
              X=O=false;
          if(X)
            Ans=1;
          if(O)
            Ans=-1;
          X=O=true;
          for(int j=0;j<4;j++)
            if(Map[j][i]=='X')
              O=false;
            else if(Map[j][i]=='O')
              X=false;
            else if(Map[j][i]=='.')
              X=O=false;
          if(X)
            Ans=1;
          if(O)
            Ans=-1;
        }
      bool X=true,O=true;
      for(int i=0;i<4;i++)
        if(Map[i][i]=='X')
          O=false;
        else if(Map[i][i]=='O')
          X=false;
        else if(Map[i][i]=='.')
          X=O=false;
      if(X)
        Ans=1;
      if(O)
        Ans=-1;
      X=O=true;
      for(int i=0;i<4;i++)
        if(Map[i][3-i]=='X')
          O=false;
        else if(Map[i][3-i]=='O')
          X=false;
        else if(Map[i][3-i]=='.')
          X=O=false;
      if(X)
        Ans=1;
      if(O)
        Ans=-1;
      if(Ans==1)
        printf("X won\n");
      else if(Ans==-1)
        printf("O won\n");
      else
        {
          bool Full=true;
          for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
              if(Map[i][j]=='.')
                Full=false;
          printf(Full?"Draw\n":"Game has not completed\n");
        }
    }
  return 0;
}

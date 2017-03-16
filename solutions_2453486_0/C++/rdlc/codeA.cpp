#include<iostream>
using namespace std;
int main()
{
  int win,dots,t,tt=1,count[2][10],i,j;
  char ch,mat[4][4];
  cin>>t;
  while(t--)
  {
     dots=0;
     win=0;
     for(i=0;i<2;i++)
     {for(j=0;j<10;j++)
     {count[i][j]=0;}}
     for(i=0;i<4;i++)
     {
        for(j=0;j<4;j++)
        {
           cin>>mat[i][j];
           if(mat[i][j]=='X')
           {
             count[0][j]++;count[0][4+i]++;
             if(j==i)
             count[0][8]++;
             if(j+i==3)
             count[0][9]++;
           }
           else if(mat[i][j]=='O')
           {
             count[1][j]++;count[1][4+i]++;
             if(j==i)
             count[1][8]++;
             if(j+i==3)
             count[1][9]++;
           }
           else if(mat[i][j]=='T')
           {
             count[1][j]++;count[1][4+i]++;count[0][j]++;count[0][4+i]++;
             if(j==i)
             {count[1][8]++;count[0][8]++;}
             if(j+i==3)
             {count[1][9]++;count[0][9]++;}
           
           }
           else
           dots++;
        }
     }
     for(i=0;i<2;i++)
     {
        for(j=0;j<10;j++)
        {
           if(count[i][j]==4)
           {
              win=i+1;
              break;
           }
        }
        if(win!=0)
        break;
     }
     if(win==1)
     cout<<"Case #"<<tt<<": X won\n";
     else if(win==2)
     cout<<"Case #"<<tt<<": O won\n";
     else if(dots==0)
     cout<<"Case #"<<tt<<": Draw\n";
     else
     cout<<"Case #"<<tt<<": Game has not completed\n";
     tt++;
 }
}

#include<stdio.h>
//#include<iostream>
using namespace std;
int main()
{
int t;
scanf("%d",&t);
getchar();
int count=0;
while(t--)
          {count++;
           char a[4][4];
           for(int i=0;i<4;i++)
           {for(int j=0;j<4;j++)
                   {
                    scanf("%c",&a[i][j]);
                   }
           getchar();
           }
          /*
          for(int i=0;i<4;i++)
           {for(int j=0;j<4;j++)
                   {
                    cout<<a[i][j];
                   }
           cout<<"\n";
           }*/
          int flag=-1;
          for(int i=0;i<4;i++)
                  {int x=i;
                  int y=0;
                  char present=a[x][y];
                  int co=0;
                  int j=1;
                  if(present=='T')
                  {present=a[x][1];
                  j=2;
                  co=1;}
                  //cout<<present;
                  if(present=='X' || present=='O')
                  for(j;j<4;j++)
                           {
                            if(co==0)
                                     {if(a[x][j]=='T')
                                     {co=1;
                                      continue;
                                     }
                                     }
                            
                            if(a[x][j]!=present)
                                                break;
                           }
                  if(j==4) 
                           {//cout<<i;
                           if(present=='X')
                            flag=1;
                            else
                            flag=2;
                            break;
                           }
                  }
                  
          if(flag==-1)
          for(int i=0;i<4;i++)
                  {int x=i;
                  int y=0;
                  char present=a[y][x];
                  int co=0;
                  int j=1;
                  if(present=='T')
                  {present=a[1][x];
                  j=2;
                  co=1;}
                  if(present=='X' || present=='O')
                  for(j;j<4;j++)
                           {
                            if(co==0)
                                     {if(a[j][x]=='T')
                                     {co=1;
                                      continue;
                                     }
                                     }
                            
                            if(a[j][x]!=present)
                                                break;
                           }
                  if(j==4) 
                           {if(present=='X')
                            flag=1;
                            else
                            flag=2;
                            break;
                           }
                  }
                  
                  //cout<<flag;
          
          if(flag==-1)
                  {int x=0;
                  int y=0;
                  char present=a[y][x];
                  int co=0;
                  int j=1;
                  if(present=='T')
                  {present=a[1][1];
                  j=2;
                  co=1;}
                  
                  if(present=='X' || present=='O')
                  for(j;j<4;j++)
                           {
                            if(co==0)
                                     {if(a[j][j]=='T')
                                     {co=1;
                                      continue;
                                     }
                                     }
                            
                            if(a[j][j]!=present)
                                                break;
                           }
                  if(j==4) 
                           {//cout<<"hi";
                           if(present=='X')
                            flag=1;
                            else
                            flag=2;
                            //break;
                           }
                  }
          
          if(flag==-1)
                  {int x=0;
                  int y=3;
                  char present=a[x][y];
                  int co=0;
                  int j=1;
                  if(present=='T')
                  {present=a[1][2];
                  j=2;
                  co=1;}
                  if(present=='X' || present=='O')
                  for(j;j<4;j++)
                           {
                            if(co==0)
                                     {if(a[j][4-j-1]=='T')
                                     {co=1;
                                      continue;
                                     }
                                     }
                            
                            if(a[j][4-j-1]!=present)
                                                break;
                           }
                  if(j==4) 
                           {//cout<<present;
                           if(present=='X')
                            flag=1;
                            else
                            flag=2;
                            //break;
                           }
                  }
                  
           if(flag==-1)
           for(int i=0;i<4;i++)
           for(int j=0;j<4;j++)
                       {
                        if(a[i][j]=='.')
                                        flag=0;
                        
                       }
           if(flag==-1)
                       printf("Case #%d: Draw\n\n",count);
           else if(flag==0)
                           printf("Case #%d: Game has not completed\n\n",count);
           else if(flag==1)
                           printf("Case #%d: X won\n\n",count);
           else if(flag==2)
                           printf("Case #%d: O won\n\n",count);
           
         getchar();
          }
}

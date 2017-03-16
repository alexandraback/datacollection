#include<iostream>
using namespace std;

char tab[5][5];

int main()
{
    int n;
    cin >> n;
    
    for(int x=1; x<=n; x++)
    {
              for(int i=0; i<4; i++)
                      cin >> tab[i];
              
              bool flag=true;
              
              for(int i=0; i<4; i++)
              {
                      flag=true;
                      
                      for(int j=0; j<4; j++)
                      {
                             if(tab[i][j]!='X' && tab[i][j]!='T')
                             {
                                               flag=false;
                                               break;
                             }
                      }
                      
                      if(flag)
                              break;
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": X won" << endl;
                      continue;
              }
              
              flag=true;
              
              for(int i=0; i<4; i++)
              {
                      flag=true;
                      
                      for(int j=0; j<4; j++)
                      {
                             if(tab[j][i]!='X' && tab[j][i]!='T')
                             {
                                               flag=false;
                                               break;
                             }
                      }
                      
                      if(flag)
                              break;
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": X won" << endl;
                      continue;
              }
              
              
              flag=true;
              
              for(int i=0; i<4; i++)
              {
                      if(tab[i][i]!='X' && tab[i][i]!='T')
                      {
                       flag=false;
                       break;
                      }
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": X won" << endl;
                      continue;
              }
              
              flag=true;
              
              for(int i=0; i<4; i++)
              {
                      if(tab[i][3-i]!='X' && tab[i][3-i]!='T')
                      {
                       flag=false;
                       break;
                      }
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": X won" << endl;
                      continue;
              }
              
              
              
              
              
              
              
              
              
              flag=true;
              
              for(int i=0; i<4; i++)
              {
                      flag=true;
                      
                      for(int j=0; j<4; j++)
                      {
                             if(tab[i][j]!='O' && tab[i][j]!='T')
                             {
                                               flag=false;
                                               break;
                             }
                      }
                      
                      if(flag)
                              break;
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": O won" << endl;
                      continue;
              }
              
              flag=true;
              
              for(int i=0; i<4; i++)
              {
                      flag=true;
                      
                      for(int j=0; j<4; j++)
                      {
                             if(tab[j][i]!='O' && tab[j][i]!='T')
                             {
                                               flag=false;
                                               break;
                             }
                      }
                      
                      if(flag)
                              break;
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": O won" << endl;
                      continue;
              }
              
              
              flag=true;
              
              for(int i=0; i<4; i++)
              {
                      if(tab[i][i]!='O' && tab[i][i]!='T')
                      {
                       flag=false;
                       break;
                      }
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": O won" << endl;
                      continue;
              }
              
              flag=true;
              
              for(int i=0; i<4; i++)
              {
                      if(tab[i][3-i]!='O' && tab[i][3-i]!='T')
                      {
                       flag=false;
                       break;
                      }
              }
              
              if(flag)
              {
                      cout << "Case #" << x << ": O won" << endl;
                      continue;
              }
              
              
              
              flag=true;
              for(int i=0; i<4; i++)
                      for(int j=0; j<4; j++)
                              if(tab[i][j]=='.')
                              {
                                                flag=false;
                                                break;
                              }
              
              if(flag)
                      cout << "Case #" << x << ": Draw" << endl;
              else
                      cout << "Case #" << x << ": Game has not completed" << endl;
    }
return 0;
}

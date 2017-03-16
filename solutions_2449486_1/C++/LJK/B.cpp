#include<iostream>
using namespace std;

int tab[101][101];

int a;
int b;

bool check(int x, int y)
{
     bool flag=true;
         
     for(int i=0; i<b; i++)
     {
             if(tab[x][i]>tab[x][y])
             {
                 flag=false;
                 break;
             }
     }
     
     if(flag)
             return true;
     
     for(int i=0; i<a; i++)
             if(tab[i][y]>tab[x][y])
             return false;
     
     return true;
}


int main()
{
    int z;
    cin >> z;
    
    for(int x=1; x<=z; x++)
    {
            cin >> a;
            cin >> b;
            
            for(int i=0; i<a; i++)
                    for(int j=0; j<b; j++)
                            cin >> tab[i][j];
            
            bool flag=true;
            
            for(int i=0; i<a; i++)
            {
                    for(int j=0; j<b; j++)
                         if(!check(i,j))
                         {
                                        flag=false;
                                        break;
                         }
                     if(!flag)
                             break; 
            }
            
            if(flag)
              cout << "Case #" << x << ": YES" << endl;
            else
              cout << "Case #" << x << ": NO" << endl;
            
    }
return 0;
}

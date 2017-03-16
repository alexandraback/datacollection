#include <fstream>
#include <queue>
#include <cstdio>
#include <iostream>
#define ii pair<int,int>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
char tab[50][50];
bool touched[50][50];
bool ok;
int r,c;

void stampaTabella()
{
     for(int i=0; i<r; i++)
     {
         for(int j=0; j<c; j++)
         {
              out << tab[i][j];   
         }    
         out << endl;
     }
}

void stampaTabella2()
{
     for(int i=0; i<r; i++)
     {
         for(int j=0; j<c; j++)
         {
              cout << tab[i][j];   
         }    
         cout << endl;
     }
}

void stampaTabella3()
{
     for(int i=0; i<r; i++)
     {
         for(int j=0; j<c; j++)
         {
              cout << touched[i][j];   
         }    
         cout << endl;
     }
}

bool nonFuori(int x, int y)
{
     if(x>=r)
             return false;
     if(y>=c)
             return false;
     if(x<0 || y<0)
            return false;
     return true;
}

bool vicini(int x, int y)
{
    int ris=0;
    for(int i=-1; i<=1; i++)
            for(int j=-1; j<=1; j++)
                    if(tab[x+i][y+j]=='*' && nonFuori(x+i,y+j))
                          return true;
     return false;
}

bool accettabile(int x, int y)
{
     if(vicini(x,y))
                   return false; 
     for(int i=0; i<r; i++)
             for(int j=0; j<c; j++)
                     if(tab[i][j]=='*')
                         touched[i][j]=true;
                     else
                         touched[i][j]=false;
     // inizia la bfs
     //stampaTabella2();
     touched[x][y]=true;
     queue<ii > bfs;
     bfs.push(ii(x,y));
     while(!bfs.empty())
     {
                        //stampaTabella3();
                       // getchar();
         ii v=bfs.front();
         bfs.pop();  
         for(int i=-1; i<=1; i++)
                 for(int j=-1; j<=1; j++)
                         if(nonFuori(v.first+i,v.second+j))
                         if(!touched[v.first+i][v.second+j])
                         {
                              touched[v.first+i][v.second+j]=true;
                              if(!vicini(v.first+i,v.second+j))
                                    bfs.push(ii(v.first+i,v.second+j));                 
                         }         
     }
     
     //finisce la bfs
     for(int i=0; i<r; i++)
             for(int j=0; j<c; j++)
                     if(!touched[i][j])
                                       return false;
     return true;
}

bool assegnaC()
{
    for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                    if(tab[i][j]=='.')
                    {
                        tab[i][j]='c';
                        if(accettabile(i,j))
                               return true;
                        else
                            tab[i][j]='.';              
                    }
    return false;
            
}

void crea(int x, int y, int m)
{
     if(ok)
     {
           return  ;
     }
     if(m==0)
         ok=assegnaC();
     else if(x<=r && y<=c)
     {
         if(m>0)
         {
                tab[x][y]='*';
                m--;
                if(x+1<r)
                         crea(x+1,y,m);
                else if(y+1<c)
                     crea(0, y+1,m);
         }
         if(!ok)
         {
               m++;
               tab[x][y]='.'; 
               if(x+1<r)
                         crea(x+1,y,m);
                else if(y+1<c)
                     crea(0, y+1,m);
         }
         
     }
}

int main()
{
    int t,m;
    in >> t;
    for(int i=1; i<=t; i++)
    {
          ok=false;
          in >> r >> c >> m;
          if(r*c==m+1)
          {
          for(int s=0; s<r; s++)
                  for(int j=0; j<c; j++)
                          tab[s][j]='*';
          tab[0][0]='c';
          ok=true;
          }
          else
          {
          for(int s=0; s<r; s++)
                  for(int j=0; j<c; j++)
                          tab[s][j]='.';
          crea(0,0,m);
          }
          out << "Case #" << i << ":" << endl;
          if(ok)
                stampaTabella();
          else
              out << "Impossible" << endl;
    }
    return 0;
}

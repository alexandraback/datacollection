#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cassert>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define vi vector < int >
#define pb push_back
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define all(x) x.begin(),x.end()

char grid[55][55];
int r,c;
int E;
void print()
{
     int i,j;
     for(i=0;i<r;i++)
     {
        for(j=0;j<c;j++)
        cout<<grid[i][j];
        cout<<endl;
     }
     cout<<endl;
}

void clear()
{
     int i,j;
     for(i=0;i<r;i++)
     {
        for(j=0;j<c;j++)
        grid[i][j] = 'e';
     }
}

int id[]={0,1,2,3};
int dirx[]={1,0,-1,0};
int diry[]={0,1,0,-1};
int dirx2[]={1,0,-1,0,1,-1,1,-1};
int diry2[]={0,1,0,-1,-1,1,1,-1};

int M;


void dfs(int x,int y)
{
     if(M==0)
     return;
     //cout<<x<<":"<<y<<":"<<m<<endl;
     grid[x][y]='*';
     M--;
     int i;
     for(i=0;i<4;i++)
     {
        int nx = x + dirx[id[i]];
        int ny = y + diry[id[i]];
        if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]=='e')
        {
           dfs(nx,ny);
        }
     }
}

int is_zero(int x,int y)
{
    int i;
    //print();
    for(i=0;i<8;i++)
    {
       int nx = x+dirx2[i];
       int ny = y+diry2[i];
       //if(nx>=0 && ny>=0 && nx<r && ny<c)
       //cout<<grid[nx][ny]<<endl;
       if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]=='*')
       return 0;
    }
    return 1;
}

void dfs2(int x,int y)
{
     int i;
     grid[x][y] = '.';
     E++;
     if(!is_zero(x,y))
     return;
     //grid[x][y] = '0';
     for(i=0;i<8;i++)
     {
        int nx = x+dirx2[i];
        int ny = y+diry2[i];
        if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]=='e')
        {
           dfs2(nx,ny);
        }
     }
}

int check(int m)
{
    int i,j;
    int f = 0;
    E = 0;
    for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           
           if(grid[i][j]=='e')
           {
              //cout<<"A";
              if(!f && is_zero(i,j))
              {
         //           cout<<"YES\n";
                    dfs2(i,j);
           //         print();
                    grid[i][j]='c';
                    f=1;
                    //cout<<E<<endl;
              }
           }
       }
    }
    return (E+m == r*c);
}


int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int t,tc=1,i,j,m;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d%d%d",&r,&c,&m);
              printf("Case #%d:\n",tc++);
              //cout<<r<<":"<<c<<":"<<m<<endl;              
    
              int f = 0;
              for(i=0;i<r && !f;i++)
              {
                  for(j=0;j<c && !f;j++)
                  {
                     int iter = 10;
                     while(iter--)
                     {
                      next_permutation(id,id+4);
                      clear();
                      M = m;
                      dfs(i,j);
                //      print();
                      if(check(m))
                      {
                        f = 1;
                        break;
                      }
                     }
                  }
              }
              if(f)
              {
  //                 continue;
                  for(i=0;i<r;i++)
                  {
                     for(j=0;j<c;j++)
                     {
                        printf("%c",grid[i][j]);
                     }
                     printf("\n");
                  }
              }   
              else if(m==r*c-1)
              {
//                   continue;
                   for(i=0;i<r;i++)
                   {
                      for(j=0;j<c;j++)
                      {
                         if(i==r-1 && j==c-1)
                         printf("c");
                         else
                         printf("*");
                      }
                      printf("\n");
                   }
              } 
              else
              {
                  printf("Impossible\n");
              }
    }
    //system("pause");
    return 0;
}


#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<queue>
#include <iterator>
#include <deque>
#define Pi 3.141592
#define E 0.000001
#define P 1000000009ll
#define MA(a,b) (a>b?a:b)
#define MI(a,b) (a<b?a:b)
#define minn min_element
#define maxx max_element
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pf push_front
#define S size
using namespace std;
int I,J,n,m,p,i,j,k,t,SZ,T;
char c[5][5];

   FILE *fi=freopen("A-large.in","r",stdin);
   FILE *fo=freopen("text.txt","w",stdout);
bool u(char x,char y)
{
     if (x=='T') return 1;
     return (x==y);
     }
char d()
{
     if ( u(c[1][1],'X') && u(c[2][2],'X') && u(c[3][3],'X') && u(c[4][4],'X') ) return 'X';
     if ( u(c[1][1],'O') && u(c[2][2],'O') && u(c[3][3],'O') && u(c[4][4],'O') ) return 'O';
     if ( u(c[4][1],'X') && u(c[3][2],'X') && u(c[2][3],'X') && u(c[1][4],'X') ) return 'X';
     if ( u(c[4][1],'O') && u(c[3][2],'O') && u(c[2][3],'O') && u(c[1][4],'O') ) return 'O';
     for (i=1;i<=4;i++)
     {
          if ( u(c[i][1],'X') && u(c[i][2],'X') && u(c[i][3],'X') && u(c[i][4],'X') ) return 'X';
          if ( u(c[i][1],'O') && u(c[i][2],'O') && u(c[i][3],'O') && u(c[i][4],'O') ) return 'O';
          if ( u(c[1][i],'X') && u(c[2][i],'X') && u(c[3][i],'X') && u(c[4][i],'X') ) return 'X';
          if ( u(c[1][i],'O') && u(c[2][i],'O') && u(c[3][i],'O') && u(c[4][i],'O') ) return 'O';
     } 
     for (i=1;i<=4;i++)
     for (j=1;j<=4;j++)
     if (c[i][j]=='.') return 'Z';
     return 'T';
     }
int main()
{
     cin>>n;
    while (n--)
    {
          k++;
          for (i=1;i<=4;i++)
          for (j=1;j<=4;j++)
          cin>>c[i][j];
          if (d()=='O' || d()=='X') cout<<"Case #"<<k<<": "<<d()<<" won"<<endl; else
          if (d()=='T')             cout<<"Case #"<<k<<": Draw"<<endl; else
                                    cout<<"Case #"<<k<<": Game has not completed"<<endl; 
                                    
                                    
          }
    return 0;
}

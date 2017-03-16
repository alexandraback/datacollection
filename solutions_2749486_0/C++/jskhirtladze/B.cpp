#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);

bool good(int i)
{
 if ( i<0 ) return false;
 if ( i>400 ) return false;
 return true;
}

const int N=410;
bool f[N][N][501];
char c[N][N][501],q;
int j,l,t,x,y;
string answer;

main()
{
 f[200][200][0]=true;
 c[200][200][0]='X';
 for ( j=0;j<500;j++ )
  for ( x=0;x<=400;x++ )
   for ( y=0;y<=400;y++ )
    if ( f[x][y][j] )
     {
      if ( good(x+j+1) )
       {
        f[x+j+1][y][j+1]=true;
        c[x+j+1][y][j+1]='E';
       }
      if ( good(x-j-1) )
       {
        f[x-j-1][y][j+1]=true;
        c[x-j-1][y][j+1]='W';
       }
      if ( good(y+j+1) )
       {
        f[x][y+j+1][j+1]=true;
        c[x][y+j+1][j+1]='N';
       }
      if ( good(y-j-1) )
       {
        f[x][y-j-1][j+1]=true;
        c[x][y-j-1][j+1]='S';
       }
     }

// cout<<"done"<<endl;

 cin>>t;
 for ( l=1;l<=t;l++ )
  {
   cin>>x>>y;
   x+=200;
   y+=200;
//   cout<<"we try to find"<<endl;

   for ( j=0;j<=500;j++ )
    if ( f[x][y][j] ) break;

  // cout<<j<<endl;

   answer="";
   while ( c[x][y][j]!='X' )
    {
     answer+=c[x][y][j];
     q=c[x][y][j];
     if ( q=='N' ) y-=j;
     if ( q=='S' ) y+=j;
     if ( q=='E' ) x-=j;
     if ( q=='W' ) x+=j;
     j--;
    }
   reverse(answer.begin(),answer.end());


   cout<<"Case #"<<l<<": "<<answer<<endl;
  }
}

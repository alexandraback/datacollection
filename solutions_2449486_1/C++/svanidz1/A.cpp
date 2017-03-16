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
int I,J,n,m,p,i,j,k,SZ,T,A,B;
int c[150][150];

   FILE *fi=freopen("B-large.in","r",stdin);
   FILE *fo=freopen("text.txt","w",stdout);
bool d()
{
     for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
     {
         A=B=0;
         for (I=1;I<=n;I++)
         if (c[I][j]>c[i][j]) A=1;
         for (J=1;J<=m;J++)
         if (c[i][J]>c[i][j]) B=1;
         if (A+B>1) return 0;
         }
         return 1;
     }
int main()
{
    int t;
     cin>>t;
    while (t--)
    {
          k++;
          cin>>n>>m;
          for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
          cin>>c[i][j];
          if (d()) cout<<"Case #"<<k<<": YES"<<endl; else
                   cout<<"Case #"<<k<<": NO"<<endl; 
                                    
                                    
          }
    return 0;
}

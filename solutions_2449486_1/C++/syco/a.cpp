#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define INF (int)1e9
int n,m,a[102][102],b[102][102] ;

int main()
{
 int runs ;
 cin >> runs ;
 for(int t = 1;t <= runs;t++)
 {
  cin >> n >> m ;
  for(int i = 0;i < n;i++)
   for(int j = 0;j < m;j++)
    cin >> a[i][j] ;
  
  for(int i = 0;i < n;i++)
   for(int j = 0;j < m;j++)
    b[i][j] = 100 ;
    
  for(int k = 100;k >= 1;k--)
  {
   for(int i = 0;i < n;i++)
   {
    bool can = true ;
    for(int j = 0;j < m;j++)
     if(a[i][j] > k)
      can = false ;
    if(can)
     for(int j = 0;j < m;j++)
      b[i][j] = k ;
   }

   for(int j = 0;j < m;j++)
   {
    bool can = true ;
    for(int i = 0;i < n;i++)
     if(a[i][j] > k)
      can = false ;
    if(can)
     for(int i = 0;i < n;i++)
       b[i][j] = k ;
   }
  }
  
  bool valid = true ;
  for(int i = 0;i < n;i++)
   for(int j = 0;j < m;j++)
    if(a[i][j] != b[i][j])
     valid = false ;
  
  if(valid) printf("Case #%d: YES\n",t) ;
  else printf("Case #%d: NO\n",t) ;
 }
 return 0 ;
}

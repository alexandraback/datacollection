#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;

int n,m,s,p;

int S[31][2];
int data[105];
int memo[105][105];

int mem(int pos, int sup)
{
  if( memo[pos][sup]!=-(1<<30) ) return memo[pos][sup];
  
  if(pos==n) 
  {
    if( !sup )return 0;
    return -(1<<20);
  }
  
  int res=-(1<<20);
  if(sup && S[data[pos]][1]!=-1)
   {
     int plus=0;
     if( S[data[pos]][1]>=p ) plus=1;
     res=mem( pos+1,sup-1 )+plus;
   }
  if(S[data[pos]][0]!=-1)
   {
     int plus=0;
     if( S[data[pos]][0]>=p ) plus=1;
     res=max(res,mem( pos+1,sup )+plus);
   }   
   return memo[pos][sup]=res;
  
}

int main()
{
  freopen("in","r",stdin);
  freopen("out","w",stdout);  
  memset( S,-1,sizeof(S) );
  for( int a=0;a<=10;a++ )
   for( int b=0;b<=10;b++ )
    for( int c=0;c<=10;c++ )
     {
       if( abs( a-b )>2 || abs( a-c )>2 || abs( c-b )>2 ) continue;
       else
       if( abs( a-b )==2 || abs( a-c )==2 || abs( c-b )==2 ) S[a+b+c][1]=max( S[a+b+c][1],max(a,max(b,c)) );       
       else S[a+b+c][0]=max( S[a+b+c][0],max(a,max(b,c)) );
     }
  int T;
  scanf("%d",&T);
  for( int h=0;h<T;h++ )
    {
       scanf("%d%d%d",&n,&s,&p);
       for(  int r=0;r<n;r++ )
        scanf("%d",&data[r]);
       for( int r=0;r<=n;r++ )
        for(int c=0;c<=s;c++)
         memo[r][c]=-(1<<30);
       printf("Case #%d: %d\n",h+1,mem(0,s));
    }
}

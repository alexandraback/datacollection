#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int a,b,x,y;
int sa,sb,ba[1000],bb[1000];
int i,j;
bool p;

FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);

bool check()
{
 a=x; sa=0; while ( a>0 ) { ba[sa++]=a%10; a=a/10; }
 b=y; sb=0; while ( b>0 ) { bb[sb++]=b%10; b=b/10; }
 if ( sa!=sb ) return false;
 for ( i=0;i<sa;i++ )
  {
   p=true;
   for ( j=0;j<sa;j++ )
    if ( ba[j]!=bb[(i+j)%sb] )
     {
      p=false;
      break;
     }
   if ( p ) { return true; }
  }
 return false;
}

main()
{
 int t,k,a,b,res;
 cin>>t;
 for ( k=1;k<=t;k++ )
  {
   cin>>a>>b;
   res=0;
   for ( x=a;x<=b;x++ )
    for ( y=x+1;y<=b;y++ )
     if ( check() ) res++;
   cout<<"Case #"<<k<<": "<<res<<endl;
  }
}

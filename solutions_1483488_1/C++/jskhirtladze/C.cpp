#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);

int a,b,x,y,r,c,res;

void f()
{
 y=x;
 r=1;
 c=0;
 while ( y>0 )
  {
   c++;
   y=y/10;
   r=r*10;
  }
 r=r/10;
 y=x;
 while ( c-- )
  {
   y=(y%10)*r+(y/10);
   if ( x==y ) return;
   if ( a<=y && y<=b && y>=r) res++;
  }
}

main()
{
 int t; cin>>t;
 for (int k=1;k<=t;k++ )
  {
   cin>>a>>b; res=0;
   for ( x=a;x<=b;x++ ) f();
   cout<<"Case #"<<k<<": "<<res/2<<endl;
  }
}

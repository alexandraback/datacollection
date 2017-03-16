#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);

int t,k,i,s,n,p,x,res,cnt;

main()
{
 cin>>t;
 for ( k=1;k<=t;k++ )
  {
   cin>>n>>s>>p;
   res=0;
   cnt=0;
   for ( i=1;i<=n;i++ )
    {
     cin>>x;
     if ( x>=(3*p-2) ) res++;
     else if ( x>=(3*p-4) && x>=2 && x<=28 ) cnt++;
    } 
   res+=min(cnt,s);
   cout<<"Case #"<<k<<": "<<res<<endl;
  }   
}

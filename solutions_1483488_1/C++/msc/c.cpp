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

int n,m;
int A,  B;
int pre[10];
int d[10];
int main()
{
  freopen("in","r",stdin);
  freopen("out","w",stdout);  
  pre[0]=1;
  for( int r=1;r<=8;r++ )   pre[r]=pre[r-1]*10;
  int T;
   scanf("%d",&T);
   for( int h=0;h<T;h++ )
    {
       scanf("%d%d",&A,&B);
       n=0;
       int tA=A;
       int res=0;
       while(tA!=0)n++,tA/=10;
       for( int r=A;r<=B;r++ )
        {
         int R=r;
          bool end=false;
          for( int c=0;c<n;c++ )
           {                          
             R=R/pre[n-1]+(R*10)%pre[n];
             for( int j=0;j<c;j++ ) if( R==d[j] ) {
              end=true;
              break;
             }
             if(end) break;
             d[c]=R;
             if(R>r && R<=B) res++;
           }
        }
       
       printf("Case #%d: %d\n",h+1,res);
       
    }
}

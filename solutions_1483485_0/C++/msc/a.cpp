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


/*3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv


Output
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up*/

string A="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvq qee";
string B="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upa zoo";



int mapa[512];
int flag[512];
char pal[1000000];
int main()
{
  freopen("in","r",stdin);
  freopen("out","w",stdout);  
  memset(mapa,-1,sizeof(mapa));
  for( int r=0;r<A.size();r++ )
   mapa[A[r]]=B[r],flag[B[r]]=1;
   
  for( int r='a';r<='z';r++ ) 
     if( mapa[r]==-1 )  
      for( int c='a';c<='z';c++ )
       if( !flag[c] ) mapa[r]=c;
  
   
   gets(pal);
   int T;
   sscanf(pal,"%d",&T);
   for( int h=0;h<T;h++ )
    {
       gets(pal);
       n=strlen(pal);
       
       for( int r=0;r<n;r++ )
        pal[r]=mapa[pal[r]];
       
       printf("Case #%d: %s\n",h+1,pal);
    }
}

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

int main()
{
 int runs ;
 cin >> runs ;
 for(int t = 1;t <= runs;t++)
 {
  printf("Case #%d:\n",t) ;
  int n,a[22] ;
  cin >> n ;
  map<int,int> sum ;
  for(int i = 0;i < n;i++) cin >> a[i] ;
  int found = 0 ;
  for(int i = 1;i < 1 << n;i++)
  {
   int now = 0 ;
   for(int j = 0;j < n;j++) if(i & 1 << j) now += a[j] ;
   if(!sum.count(now)) sum[now] = i ;
   else
   {
    found = true ;
    for(int j = 0;j < n;j++) if(sum[now] & 1 << j) printf("%d ",a[j]) ;
    printf("\n") ;
    for(int j = 0;j < n;j++) if(i & 1 << j) printf("%d ",a[j]) ;
    printf("\n") ;
    break ;
   }
  }
  if(!found) printf("impossible\n") ;
 }

 return 0 ;
}

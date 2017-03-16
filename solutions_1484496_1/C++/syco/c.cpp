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
int n ;
long long a[502] ;
map<long long,long long> sum ;

int main()
{
 int runs ;
 cin >> runs ;
 for(int t = 1;t <= runs;t++)
 {
  printf("Case #%d:\n",t) ;

  cin >> n ;
  for(int i = 0;i < n;i++) cin >> a[i] ;
  n = 60 ;

  sum.clear() ;
  int iter = 0 ;
  while(++iter)
  {
   long long now = 0,take = 0 ;
   for(int j = 0;j < n;j++) if(rand() % 2 == 0)
   { 
    now += a[j] ;
    take ^= 1LL << j ;
   }

   if(iter % 10000 == 0) cerr << iter << endl ;

   if(!sum.count(now)) sum[now] = take ;
   else
   {
    for(int j = 0;j < n;j++) if(take & 1LL << j) printf("%lld ",a[j]) ;
    printf("\n") ;
    
    long long take2 = sum[now] ;
    for(int j = 0;j < n;j++) if(take2 & 1LL << j) printf("%lld ",a[j]) ;
    printf("\n") ;
    break ;
   }
  }
  cerr << "iter: " << iter << endl ;
 }

 return 0 ;
}

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
#define MAXN 202

int main()
{
 int runs ;
 cin >> runs ;
 for(int t = 1;t <= runs;t++)
 {
  printf("Case #%d:",t) ;
  int n,s[MAXN] ;
  cin >> n ;
  for(int i = 0;i < n;i++) cin >> s[i] ;
  int sum = 0 ;
  for(int i = 0;i < n;i++) sum += s[i] ;

  for(int i = 0;i < n;i++)
  {
   int low = -1,high = sum + 1 ;
   while(low + 1 < high)
   {
    int mid = low + (high - low) / 2 ;
    int score = s[i] + mid,need = 0 ;
    for(int j = 0;j < n;j++) if(i != j)
    {
     if(s[j] < score + 1)
     {
      need += score + 1 - s[j] ;
     }
    }
    if(need + mid <= sum) low = mid ;
    else high = mid ;
   }
   printf(" %.9lf",100. * high / sum) ;
  }
  printf("\n") ;
 }
 return 0 ;
}

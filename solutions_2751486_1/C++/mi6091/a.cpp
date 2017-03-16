#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s [1000005];
//int dp[1000005][2];
int k, n;
bool isVol(char c)
{
    return c == 'a' || c== 'e' || c == 'o' || c == 'i' || c == 'u';
}
long long solve ()
{
  scanf ("%s%d", &s, &k);
  
  n = strlen (s);
  
  long long res = 0; 
  int i;
  int last = 0;
  long long bigRes;
  int coolIndex = -1;
  for(i = 0; i < n;i++)
  {
     if(isVol(s[i]))
       last = 0;
     else
       last ++;
     
     //res = res;
     
     if(last >= k)
     {
       coolIndex = i + 1 - k;
     }
     if (coolIndex != -1)
      res = res + coolIndex + 1;
  }
  
  return res;
}
int main ()
{

  int t;
    scanf ("%d", &t);
  for (int i= 1; i <=t; i ++)
    printf ("Case #%d: %lld\n", i, solve ());
  
}

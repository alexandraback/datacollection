#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=1e6;

int w[MAXN+5];
int t;

int reverse(int k)
{
  int ret=0;
  
  while(k>0)
  {
    ret = 10*ret + (k%10);
    k /= 10;
  }

  return ret;
}

int main()
{
  scanf("%d", &t);
  
  for(int i=2; i<=MAXN; i++) w[i]=2 * MAXN;
  
  w[1]=1;
  for(int i=1; i<=MAXN; i++)
  {
    w[i+1] = min(w[i+1], w[i] + 1);
    int rev = reverse(i);
    if(rev > i && rev < MAXN) w[rev] = min(w[rev], w[i] + 1);
  }
  
  for(int i=1; i<=t; i++)
  {
    int a;
    scanf("%d", &a);
    printf("Case #%d: %d\n", i, w[a]);
  }
  
  return 0;
}
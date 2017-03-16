#include<cstdio>
#include <vector>
#include <algorithm>
#include <utility>
//#include <unordered_map>

using namespace std;

#define MAX_N 100
#define MAX_A 1000001 * 2

int n;
int dati[MAX_N+1];
int mem[MAX_N+1][MAX_A+1];

int find(int i, int a)
{
  if (i==n)
    return 0;
  //printf("%d %d\n",i,a);
  if (mem[i][a] == -1)
  {
    if (dati[i] < a)
    {
      if (a <= 1000000)
        mem[i][a] = find(i+1,a+dati[i]);
      else
        mem[i][a] = find(i+1,a);
    }
    else
    {
      int el,ma;
      //printf("chiamo %d %d\n",i+1,a);
      //elimino
      el = find(i+1,a) + 1;
      if (a>1)
      {
        //mangio altro
        ma = find(i,a+a-1) +1;
        mem[i][a] = min(el,ma);
      }
      else
      {
        mem[i][a] = el;
      }
    }
  }
  //printf("%d %d ritorna %d\n",i,a,mem[i][a]);
  return mem[i][a];
}

int main()
{
  int t,a;

  scanf("%d",&t);
  for (int k=0; k<t; k++)
  {
    scanf("%d %d",&a,&n);
    for (int i=0; i<n; i++)
    {
      scanf("%d",&(dati[i]));
    }
    sort(dati,dati+n);
    for (int i=0; i<n; i++)
      for (int j=0; j<=MAX_A; j++)
        mem[i][j] = -1;
    /*for (int i=0; i<n; i++)
      printf("%d ",dati[i]);
      printf("\n");*/
    int mosse = find(0,a);
    printf("Case #%d: %d\n",k+1,mosse);
  }
  return 0;
}

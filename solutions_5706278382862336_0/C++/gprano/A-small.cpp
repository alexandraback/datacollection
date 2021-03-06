#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull high = (ull) 1<<40;

int main()
{
  int nb_cas;
  scanf("%d",&nb_cas);
  for(int cas = 1; cas <= nb_cas; cas++)
    {
      printf("Case #%d: ",cas);
      ull p,q;
      scanf("%llu/%llu",&p,&q);
      if(high % q != 0)
	printf("impossible\n");
      else
	{
	  int k = 1;
	  ull hk = 2;
	  while(hk*p < q)
	    {
	      k++;
	      hk = (ull) hk * 2;
	    }
	  printf("%d\n",k);
	}
      
    }
  return 0;
}

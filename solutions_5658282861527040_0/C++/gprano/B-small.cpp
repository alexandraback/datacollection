#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;



int main()
{
  int nb_cas;
  scanf("%d",&nb_cas);
  for(int cas = 1; cas <= nb_cas; cas++)
    {
      printf("Case #%d: ",cas);
      int a,b,k;
      scanf("%d%d%d",&a,&b,&k);
      int score=0;
      for(int i =0; i < a; i++)
	for(int j = 0; j < b; j++)
	  if((i&j)<k)
	    score++;
      printf("%d\n",score);      
    }
  return 0;
}

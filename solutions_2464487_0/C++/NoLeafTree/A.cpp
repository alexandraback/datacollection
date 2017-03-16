#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

long long r,t;

int main()
{ 
  int T,ncase=1;
  scanf("%d",&T);
  while(ncase<=T)
    {
      scanf("%lld %lld",&r,&t);
      int tr;
      double ink = t;
      double pre,cur;
      tr = r;
      int count = 0;
      while(1)
	{
	  pre = tr*tr;
	  cur = (tr+1)*(tr+1);
	  if( ink < cur-pre)
	    break;
	  ink -= (cur-pre);
	  tr+=2;
	  count++;
	}
      printf("Case #%d: %d\n",ncase++,count);
    }
  return 0;
}

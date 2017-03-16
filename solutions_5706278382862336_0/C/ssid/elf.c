#include <stdio.h>
int main()
{
  unsigned long long p,q;
  int t,j=0;
  scanf("%d",&t);
  while(t--)
    {j++;
      scanf("%lld/%lld",&p,&q);
      //printf("%lld %lld\n",p,q);
      int level=0;int pointer=0;int counter=0;
      int possible=0;
      if(q%2==0)
	while((p!=q)&&(q%2==0))
	  {counter++;
	    while((p<q)&&(q%2==0))
	      {
		q=q/2;
		level++;
	      }
	    
	    if(p>q){p=p-q;if(counter==1)pointer=level;}
	    
	  }
      if(p==q)possible=1;
      if(pointer!=0)level=pointer;
      if(possible==0)printf("case #%d: impossible\n",j);
      else printf("case #%d: %d\n",j,level);





    }
}

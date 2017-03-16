#include "stdafx.h"
#include "math.h"

int main()
{ int tt, ttt, n, a, i;
  double d, t0, x0, t1, x1, ac, t, l, k, lx;
  t1 =0; x1=0;
  freopen( "input.txt", "r", stdin );
  freopen( "output.txt", "w", stdout );    
  scanf("%d", &ttt);
  for(tt=1; tt<=ttt; ++tt)
  { scanf("%lf%d%d", &d, &n, &a);
    scanf("%lf%lf", &t0, &x0);    
	if(n==2) scanf("%lf%lf", &t1, &x1);
	printf("Case #%d:\n", tt);	
	for(i=0; i<a; ++i)
	{scanf("%lf", &ac);
	 if(n==1)
	 {t = sqrt(2.0*d/ac);
	 } else
	 {k = (x1-x0)/t1;
	  l = (k+sqrt(k*k+2.0*ac*x0))/ac;
	  lx = k*l+x0;
	  if(lx<=d)
	  {t=(d-x0)/k;
	  } else
	  {t = sqrt(2.0*d/ac);
	  }
	 }
	 printf("%.7lf\n",t);
	}
  } 
  return 0;
}

#include "stdafx.h"
#include "algorithm"

int main()
{ int tt, ttt, n, i, j, q, a[200], b[200], s, ss;  
  double d, d1;  
  freopen( "input.txt", "r", stdin );
  freopen( "output.txt", "w", stdout );    
  scanf("%d", &ttt);
  for(tt=1; tt<=ttt; ++tt)
  { scanf("%d", &n);
    s=0;
    for(i=0; i<n; ++i)
	{scanf("%d", &q);
	 a[i]=q;
	 b[i]=q;
	 s += q;
	}	
	std::sort(b, b+n);
	printf("Case #%d:", tt);
	for(i=0; i<n; ++i)
	{d=1.; 
	 ss=s-a[i];
	 for(j=0;j<n-1;++j)
	 {d1=((double)(ss+s-(n-j-1)*a[i]))/s/(n-j);
	  //printf(" !%lf", d1);	 
	  if(d1<0) d1=0;
	  if((j==0 || b[n-j]>=a[i]+s*d1) && d1<d) d=d1;
	  ss -= b[n-j-1];
	 }	 
	 printf(" %lf", d*100);	 
	}
	printf("\n");
  } 
  return 0;
}
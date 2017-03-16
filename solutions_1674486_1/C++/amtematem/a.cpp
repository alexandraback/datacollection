#include "stdafx.h"

int main()
{ int tt, ttt, n, i, j, m[1000], a[1000][10], b[1000], s, k, kk, q, ok;  
  freopen( "input.txt", "r", stdin );
  freopen( "output.txt", "w", stdout );    
  scanf("%d", &ttt);
  for(tt=1; tt<=ttt; ++tt)
  { scanf("%d", &n);
    for(i=0; i<n; ++i)
	{ scanf("%d", &m[i]);	  
	  for(j=0; j<m[i]; ++j)
	  { scanf("%d", &k);
	    a[i][j] = k-1;
	  }
	  b[i]=0;	  
	}
	/*for(i=0; i<n; ++i)
	{ printf("!%d\n", m[i]);
	  for(j=0; i<m[i]; ++j)
	  { printf("%d ", a[i][j]);	    
	  }	  
	}*/
    for(kk=0; kk<n; ++kk)
	{for(i=0; i<n; ++i) b[i]=0;	
	s=1; k=1; b[kk]=k; ok=0;
	while(s)
	{s=0;
	 for(i=0; i<n; ++i)
	 {if(b[i]==k)
	  {for(j=0; j<m[i]; ++j)
	   {q=a[i][j];
		if(b[q]!=0)
	    {ok=1;
	     break;
	    } else
        if(b[q]==0)
		{b[q]=k+1;
		 s=1;
		}
	   }
	  }
	  if(ok) break;
	 }
	 if(ok) break;
	 ++k;
	}
	if(ok) break;
	}
	if(ok) 
	 printf("Case #%d: Yes\n", tt);
	else
     printf("Case #%d: No\n", tt);
  } 
  return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include "ttmath/ttmath.h"  // available at http://www.ttmath.org/

using namespace std;


int main()
{
	int T;
	scanf("%d\n",&T);  
	for(int i=1; i<=T; i++)
	{
        long long r, t, n;
        scanf("%llu %llu\n",&r, &t);
        
        ttmath::Big<10,20> rr;
        ttmath::Big<10,20> tt;
        //ttmath::Big<1,2> nn;
        ttmath::Big<10,20> nn;
        
        rr=r;
        tt=t;
        
        //n=0.25+(0.0+r)/2.0/(sqrt(1.0-1.0/r+(1.0+8*t)/((0.0+r)*r*4))+1)*(1.0+8*t-4*r)/(4.0*r*r);
        
        nn=Floor((-rr*2+1+Sqrt(rr*rr*4-rr*4+1+tt*8))/4);
        
        printf("Case #%d: %s\n",i,nn.ToString().c_str());
	}

  
  return 0;
}

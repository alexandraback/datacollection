#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int main()
{
	int T;
	scanf("%d\n",&T);  
	for(int i=1; i<=T; i++)
	{
        long long r, t, n;
        scanf("%llu %llu\n",&r, &t);
        
        //n=0.25+(0.0+r)/2.0/(sqrt(1.0-1.0/r+(1.0+8*t)/((0.0+r)*r*4))+1)*(1.0+8*t-4*r)/(4.0*r*r);
        
       n=(1.0-2*r+sqrt(4*r*r-4*r+1+8*t))/4;
        
        printf("Case #%d: %llu\n",i,n);
	}

  
  return 0;
}

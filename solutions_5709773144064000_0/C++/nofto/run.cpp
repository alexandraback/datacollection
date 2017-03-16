#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		double C, F, X;
		scanf("%lf %lf %lf",&C,&F,&X);
		int k=max(0.0,ceil(X/C-2.0/F-1.0));
		double time=X/(2.0+k*F);
		for(int i=0;i<k;i++) time+=C/(2.0+i*F);
		printf("Case #%d: %0.7f\n",t,time);				
	}
  return 0;
}

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
int ti,T;scanf("%d",&T);
for(ti=0;ti<T;ti++)
{
	 double telap=0;	
	 double C,F,X;	
	 double cf,t1,t2;
	 scanf("%lf %lf %lf",&C,&F,&X);
	cf=2;
	
	while(1)
	{
		t1=X/cf;
		t2=C/cf+X/(cf+F);
		if(t1<t2)
		{
			telap+=t1;break;
		}
		telap+=C/cf;
		cf+=F;
		//printf("Building another:%.3f\n",cf);
	}
	
	printf("Case #%d: %.7f\n",ti+1,telap);
}
return 0;
}
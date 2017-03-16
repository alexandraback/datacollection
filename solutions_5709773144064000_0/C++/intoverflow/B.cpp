#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
std::ios_base::sync_with_stdio(0);
int T;
cin>>T;
	for (int ct=1;ct<=T;ct++)
	{
	double C,F,X,time=0,rate=2;
	cin>>C>>F>>X;
		while(X/rate>C/rate+X/(rate+F))
		{
		time+=C/rate;
		rate+=F;
		}
		time+=X/rate;
		printf("Case #%d: %.7lf\n",ct,time);
	}
}

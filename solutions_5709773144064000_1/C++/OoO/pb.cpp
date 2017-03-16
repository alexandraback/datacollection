#include<iostream>
#include<stdio.h>
using namespace std;
double C,F,X;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("b.txt","w",stdout);
	int T,cases;
	double answer,accum;
	cin>>T;
	for(cases=1;cases<=T;cases++)
	{
		cin>>C>>F>>X;
		accum=2.0;
		answer=0.0;
		while(true)
		{
			if(C/accum+X/(accum+F) > X/accum)
				break;
			answer+=C/accum;
			accum+=F;
		}
		answer+=X/accum;
		printf("Case #%d: %.7lf\n", cases, answer);
	}
	return 0;
}
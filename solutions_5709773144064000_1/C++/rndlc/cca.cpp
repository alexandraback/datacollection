#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long double c,f,x,current,pr,ne,sm;
	int i,j,t;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		sm=0.0;
		current=2.0;
		cin>>c>>f>>x;
		pr=x/2;
		ne=sm+c/2+x/(2+f);
		while(ne<pr)
		{
			pr=ne;
			sm+=c/current;
			current+=f;
			ne=sm+c/current+x/(current+f);
		}
		printf("Case #%d: %.7Lf\n",i,pr);
	}
}
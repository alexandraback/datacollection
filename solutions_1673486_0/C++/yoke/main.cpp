#include <iostream>
#include <stdio.h>
using namespace std;

int typed,total;
double p[21];

double st1(double ppp)
{
	int a = total - typed + 1;
	int b = 2*total - typed + 2;
	double result = ppp*a + (1- ppp)*(b);
	return result;
}

double st3()
{
	return (double)(total + 2);
}

double st2(int front, double ppp)
{
	int del = typed - front;
	int a = total - front + 1;
	int b = total - front + total + 2;
	double result = ppp*a + (1-ppp)*b + del;
	return result;
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	int cases;
	cin>>cases;

	for(int i =1;i<=cases;i++)
	{
		double PPP = 1;
		cin>>typed>>total;
		for(int j = 0;j<typed;j++)
		{
			cin>>p[j];
			PPP *= p[j];
		}

		double min = 1000000;
		double temp;

		temp = st1(PPP);
		if(temp < min)min = temp;
		temp = st3();
		if(temp < min)min = temp;
		for(int i = typed; i>0;i--)
		{
			PPP /= p[i - 1];
			temp = st2(i-1, PPP);
			if(temp < min)min = temp;
		}

		printf("Case #%d: %0.6f\n",i,min);
	}


	return 0;
}

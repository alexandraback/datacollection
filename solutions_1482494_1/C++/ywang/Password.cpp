#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double p[100000];
double Q[100000];
int main()
{
	int T;
	scanf("%d",&T);
	int id = 0;
	while(T--)
	{
		int A,B;
		cin >> A;
		cin >> B;
		for(int i=1;i<=A;++i)
			cin >> p[i];
		Q[0]=1;
		Q[1] = p[1];
		for(int i=2;i<=A;++i)
			Q[i] = Q[i-1]*p[i];
		double min = -(B+1)*Q[A];
		for(int y=1;y<=A;++y)
		{
			double t = 2*y-(B+1)*Q[A-y];
			if(t<min)
				min = t;
		}
		min += 2*B+2-A;

		++id;
		if(B+2 < min)
		{
			min = B+2;
			printf("Case #%d: %.6lf\n",id,min);
		}
		else
		{
			printf("Case #%d: %.6lf\n",id,min);
		}
	}
	return 0;
}

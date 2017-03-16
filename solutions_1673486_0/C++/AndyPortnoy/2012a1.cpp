#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

const int maxn = 100000;
double numbers[maxn];

int n, total;
string line;


void read() {
	scanf("%d",&n);
	scanf("%d",&total);
//printf("n:%d\n",n);
//printf("total:%d\n",total);
	for (int i=0;i<n;i++)
	{
		scanf("%lf", &numbers[i]);	
//printf("i:%d numbers[i]:%lf\n",i,numbers[i]);
	}


double enternow = total + 2;
double prob = 1.0;
int k;
	for(k=0;k<n;k++)
	{
		prob = prob*numbers[k];
	}
//	printf("prob:%lf\n",prob);

	int backspaces=0;
	double expected[n+1];
	for(k=0;k<n;k++)
	{
		expected[k] = prob*(total-n+1+2*k) + (1-prob)*(total-n+1+2*k+total+1);
		prob = prob/numbers[n-k-1];
//		printf("expected[k]:%lf\n",expected[k]);
	}
	for(k=0;k<n;k++)
	{
		if(expected[k]<enternow)
			enternow = expected[k];
	}
	printf("%lf\n",enternow);
//	getline(cin,line);
}

int main()
{
	int i,t;
	int k;
	int outoforder;
	scanf("%d",&t);
	getline(cin,line);
	for(i = 1; i<=t; i++)
	{
		printf("Case #%d: ", i);
		read();

		//cout<<line;

//		printf("\n");
	}
	return 0;
}

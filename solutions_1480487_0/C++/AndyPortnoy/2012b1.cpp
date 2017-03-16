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
	total = 0;
	int i;
	for (i=0;i<n;i++)
	{
		scanf("%lf", &numbers[i]);	
//printf("i:%d numbers[i]:%lf\n",i,numbers[i]);
		total = total + numbers[i];
	}
	double percent;
	double needs = double(total)*2/n;
	int runaway=0;
	int num=n;
	int pointsavail = total;
	for(i=0;i<n;i++)
	{
		if(numbers[i]>needs)
		{
			runaway=1;
			num--;
			pointsavail -= numbers[i];
		}
	}
	if(runaway==0)
	{
		for(i=0; i<n;i++)
		{
			percent = double(100)*((needs)-numbers[i])/total;
			printf("%4.6f",percent);
			printf(" ");
		}
	}
	else
	{
		needs = (double(total)+pointsavail)/num;
		for(i=0; i<n;i++)
		{
			percent = double(100)*((needs)-numbers[i])/total;
			if(percent<0)
				percent=0;
			printf("%4.6f",percent);
			printf(" ");
		}

	}
	printf("\n");
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

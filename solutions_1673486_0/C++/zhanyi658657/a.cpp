#include<stdio.h>
#include<iostream>
using namespace std;
inline void get(long a, int &five, int &two)
{
	five = 0;
	two = 0;
	long b = a;
	while(b % 5 == 0)
	{
		b /= 5;
		five++;
	}
	while(b % 2 == 0)
	{
		b /= 2;
		two ++;
	}
}
inline int getleft(long a)
{
	long b = a;
	while(b % 5 == 0)
	{
		b /= 5;
	}
	while(b % 2 == 0)
	{
		b /= 2;
	}
	return b;
}

int main()
{
	

	freopen("log.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	int testcase;
	long A, B;
	scanf("%d", &testcase);
	double *ans = new double[100005];
	double *P = new double[100005];
	for(int i = 1;i <= testcase;i++)
	{
		scanf("%ld%ld", &A, &B);
		for(int j = 1;j <= A;j++)
		{
			scanf("%lf", &P[j]);
		}
		double P0 = 1;

		for(int j = 0;j <= A;j++)
		{
			ans[j] = (2 * (A - j) + B - A + 1) + (1+B) - (1+B) * P0;
			P0 *= P[j + 1];
		}
		double max = B + 2;
		for(int j = 0;j <= A;j++)
		{
			if(ans[j] <= max)
			{
				max = ans[j];
			}
		}
		printf("Case #%d: %.6f\n",i, max);
		//cout<<max<<endl;
	}
	return 0;

	
}

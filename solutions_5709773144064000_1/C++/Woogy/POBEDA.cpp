#include <iostream>
#include <stdio.h>
using namespace std;
#pragma warning(disable : 4996)
int main()
{
	int T;
	double c, f, x, t, y = 2;;
	bool flag;
	int row1[4], otvet;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf_s("%lf%lf%lf", &c, &f, &x);
		flag = true;
		t = 0;
		y = 2;
		while (flag)
		{
			if (((c / y) + (x) / (y+f)) < (x / y))
			{
				t = t + c / y;
				y = y + f;
			}
			else
			{
				t = t + x / y;
				flag = false;
			}
		}
		printf("Case #%i: %.7lf\n",i,t);
	
	}
}

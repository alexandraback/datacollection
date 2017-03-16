#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

double c, f, x;

int main()
{
	int t, cas;
	double ret, speed;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		scanf("%lf%lf%lf", &c, &f, &x);
		ret = 0; speed = 2;
		while (1)
		{
			if (c / speed + x / (speed + f) < x / speed)
			{
				ret += c / speed;
				speed += f;
			}
			else
			{
				ret += x / speed;
				break;
			}
		}
		printf("Case #%d: %.7f\n", cas, ret);
	}
	return 0;
}

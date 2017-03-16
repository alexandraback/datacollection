#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <set>
using namespace std;

#define PRINT_CASE_NO printf("Case #%d: ", no + 1)

int main()
{
	int t;
	scanf("%d", &t);
	for (int no = 0; no < t; ++no)
	{
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double total = 0.0;
		double speed = 2.0;
		while (true)
		{
			if ((x / (speed + f) + c / speed) < x / speed)
			{
				total += c / speed;
				speed += f;
			}
			else
			{
				total += x / speed;
				break;
			}
		}
		PRINT_CASE_NO;
		printf("%.7lf\n", total);
	}
	return 0;
}
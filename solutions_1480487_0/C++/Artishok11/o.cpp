#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <string>
#include <set>

#define eps 1e-10

using namespace std;

int a[1000];
int n;
double sum = 0;

bool p(double mid,int x)
{
	mid /= 100.;
	double X = a[x] + mid * sum;
	double need = X + 0.00000001;
	double have = 1. - mid;
	for (int i = 0; i < n; i++)
	{
		if (i == x) continue;
		if (a[i] - X > eps) continue;
		double Y = X - a[i];
		have -= (Y / sum);
		if (have < -eps) return true;
	}
	return false;
};

int main()
{
	int T;
	scanf("%d",&T);	
	for (int T_t = 1; T_t <= T; T_t++)
	{
		printf("Case #%d: ",T_t);

		scanf("%d",&n);
	
		sum = 0;
	
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
	
		for (int i = 0; i < n; i++)
		{	
			double l = 0.0;
			double r = 100.0;
		
			for (int j = 0; j < 70; j++)
			{
				double mid = (l+r) / 2;
				bool F = p(mid,i);
				if (F) r = mid;
				else l = mid;

			}
			printf("%.8f ",r);
		}

		printf("\n");
	}
	
	return 0;	
}

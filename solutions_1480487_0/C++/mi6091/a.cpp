#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
double a[1000];
double sum;

bool check (double p, int id)
{
	
	double val = a[id] + (p * sum)/100;
	double left = 100.0; 
	int i;
	for (i = 0; i < n; i ++)
	{
		
		if (a[i] - val >= 0)
			continue;
		left -= (val - a[i])*100/sum;
	}
	
	//printf ("%lf\n", left); getchar ();
	return left <= 0;
	
}


double res[1000];
void solve ()
{
	
	scanf ("%d", &n);
	sum = 0; 
	int i;
	for (i = 0; i < n; i ++)
	{
		scanf ("%lf", &a[i] );
		sum += a[i];
	}
	
	
	double one = (sum*2)/n;
	
	for (i = 0; i < n; i ++)
	{
		
		double f = 0, l = 100.0, mid;
		
		while (fabs (l - f) > 1e-9)
		{
			mid = (f + l)/2.0;
			if (check(mid, i)) l = mid;
			else
				f = mid;
		}
		
		res[i] = l;
	}
	
	for (i = 0; i < n; i ++)
		printf ("%.7lf ", res[i]);
	
	printf ("\n");
	
	//printf ("%d\n", check (22.3333333, 0));
	
}

int main () 
{
	
	int t; 
	scanf ("%d", &t);
	
	for (int i = 1; i <=t; i ++)
		printf ("Case #%d: ", i), solve ();
	
	return 0;
}
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 10;

double calcTime(double c, double f, double x, int farms)
{
	double curT = 0;
	double curCookies = 0;
	double curSpeed = 2;

	double mn = curT + x / curSpeed;

	for(int i = 0; i<farms; i++)
	{
		curT += c / curSpeed;
		curSpeed += f;

		mn = min(mn, curT + x / curSpeed);
	}

	return mn;
}

int main()
{
	#define DEBUG

	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	scanf("%d", &t);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d: ", test);

		double c, f, x;

		scanf("%lf%lf%lf", &c, &f, &x);

		printf("%.8f\n", calcTime(c, f, x, 2000000));

	}

}
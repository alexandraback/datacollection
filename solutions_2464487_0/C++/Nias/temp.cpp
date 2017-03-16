#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

/*const double eps = 1e-8;

int dcmp(double a)
{
	return a < -eps ? -1 : a > eps;
}

long long solve(long long r, long long t)
{
	double a = 2.0, b = 2.0*r-1.0, c = -t*1.0;
	cout << a << " " << b << " " << c << endl;
	double right = sqrt((b*b)/(4*a*a)-c/a) - b/(2*a);
	return floor(right);
}*/

long long div(long long r, long long t)
{
	long long min = 0, max = 800000000LL, mid, ans;
	
	while(min <= max)
	{
		mid = min + max >> 1;
		if(2*mid*mid+mid*(2*r-1) <= t)
		{
			ans = mid;
			min = mid + 1;
		}
		else
			max = mid - 1;
	}
	return ans;
}

int main()
{
	freopen("d://test/a-small.in", "r", stdin);
	freopen("d://test/a-small.out", "w", stdout);
	int ca, cnt = 0;
	long long r, t;
	
	cin >> ca;
	while(ca--)
	{
		cin >> r >> t;
		cout << "Case #" << ++cnt << ": " << div(r, t) << endl;
	}
	return 0;
}
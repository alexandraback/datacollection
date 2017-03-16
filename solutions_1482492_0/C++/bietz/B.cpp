#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double D;
int N, A, T;
double t[2000];
double x[2000];

double a[250];

double solve(double acc)
{
	if (N == 1)
	{
		return sqrt(2*D / acc);
	}

	double p = 0, v = 0;
	for (int i=1; i<N; i++)
	{
		if (x[i] >= D || i == N-1)
		{
			double tf = t[i-1] + (sqrt(v*v - 2*acc*(p - D)) - v) / acc;
			return max(tf, t[i-1] + (t[i] - t[i-1]) * (D - x[i-1]) / (x[i] - x[i-1]));
		}

		double dt = t[i] - t[i-1];
		double pnew = p + v*dt + 0.5*acc*dt*dt;
		double vnew = v + acc*dt;
		if (pnew > x[i])
		{
			p = x[i];
			v = (x[i] - x[i-1]) / dt;
		}
		else
		{
			p = pnew;
			v = vnew;
		}
	}
}

int main()
{
	cin >> T;
	for (int c=1; c<=T; c++)
	{
		cin >> D >> N >> A;
		for (int i=0; i<N; i++)
			cin >> t[i] >> x[i];
		for (int i=0; i<A; i++)
			cin >> a[i];

		cout << "Case #" << c << ":" << endl;
		for (int i=0; i<A; i++)
			cout << solve(a[i]) << endl;
	}

	return 0;
}

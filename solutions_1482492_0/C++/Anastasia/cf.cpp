

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

double getTime( double a, double v, double x)
{
	double d = v*v+2*a*x;
	double x1 = (-v+sqrt(d))/a;
	return x1;
}

double getV( double x0, double x1, double t0, double t1)
{
	double v = (x1-x0)/(t1-t0);
	return v;
}

double getS( double v, double t, double a, double x )
{
	double d = (a*t)*(a*t) - 2*a*(0.5*a*t*t+v*t-x);
	double t1 = (a*t-sqrt(d))/a;
	double t2 = (a*t+sqrt(d))/a;
	double tt = min(t1, t2);
	return a*(t-tt)+v;
}

void test( int _case, FILE* pf, ifstream& cin )
{
	double d;
	int n, a;
	cin >> d >> n >> a;

	//d*=1000000;
	vector<double> v[2];
	v[0].resize(n);
	v[1].resize(n);

	
	for ( int i = 0; i < n; i++ )
	{
		cin >> v[0][i] >> v[1][i];
		//v[1][i]*=1000000;
		
	}

	fprintf(pf, "Case #%d:\n", _case );

	for ( int i = 0; i < a; i++ )
	{
		double time = 0.0;
		double cv = 0.0;
		double x0 = 0.0;
		double ac;
		cin >> ac;
		//ac*=1000000;

		for ( int j = 0; j < n; j++ )
		{
			double dst = v[1][j] - x0;
			double tt = v[0][j];
			if ( v[1][j] > d )
			{
				dst = d - x0;
				if ( j == 0 )
					tt = 0;
				else
				{
					double velocity = getV( v[1][j-1], v[1][j], v[0][j-1], v[0][j] );
					double dist = d-v[1][j-1];
					tt = v[0][j-1] + dist/velocity;
				}
			}

			double ct = getTime( ac, cv, dst );

			if ( time + ct < tt )
			{
				time = tt;
				if ( j > 0 )
					cv = getS( cv, tt - v[0][j-1], a, dst );
				else
					cv = getS( cv, tt, a, dst );
				x0 = v[1][j];
			}
			else
			{
				time += ct;
				cv = ac*ct + cv;
				x0 = v[1][j];
			}

		}


		fprintf(pf, "%.7f\n", time );

	}
}

int main()
{
	ifstream cin("a.in");
	FILE* pf = fopen( "out.txt", "w");
	
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ )
	{
		test(i+1, pf, cin);		
	}

	return 0;
}


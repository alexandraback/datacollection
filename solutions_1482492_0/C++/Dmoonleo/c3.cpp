#include<iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

double position(double t[], double x[], int N, double time)
{
	for(int i = 1; i < N; i++)
	{
		if(time <= t[i] && time >= t[i-1])
		{
			return (x[i-1]+(x[i]-x[i-1])*(time-t[i-1])/(t[i]-t[i-1]));
		}
	}
	return -1;
}

double time(double t[], double x[], int N, double pos)
{
	for(int i = 1; i < N; i++)
	{
		if(pos <= x[i] && pos > x[i-1])
		{
			return (t[i-1]+(t[i]-t[i-1])*(pos-x[i-1])/(x[i]-x[i-1]));
		}
	}
}

int main()
{
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; i ++)
	{
		double D = 0;
		int N = 0; int A = 0;
		cin >> D >> N >> A;
		//cout << "test" << endl;
		double t[N];
		double x[N];
		double tt[N];
		//double a[A];
		for(int j = 0; j < N; j++)
		{
			cin >> t[j] >> x[j];
		}
		cout << "Case #" << i+1 << ": " << endl;
		if(x[0] >= D) N = 0;
		for(int k = 0; k < A; k++)
		{
			double a;
			cin >> a;
			double lt = time(t,x,N,D);
			for(int j = 0; j < N; j++)
			{
				tt[j] = t[j] - sqrt(2*x[j]/a);
			}
			if(N > 0)
			{
				tt[N-1] = lt - sqrt(2*D/a);
				//cout << "lt: " << lt << endl;
				
				x[N-1] = D;
				t[N-1] = lt;			
			}

			double temp =  0;
			for(int j = 0; j < N; j++)
			{
				if(tt[j] > 0 && temp < tt[j])
				temp = tt[j];
				//cout << "tt " << tt[j] << endl;
			}
			cout << setprecision(7) << fixed << temp+sqrt(2*D/a) << endl;
		}

		
	}
	system("pause");
	return 0;
}

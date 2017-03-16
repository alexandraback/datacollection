#include<iostream>
using namespace std;

double position(double t[], double x[], int N, int time)
{
	for(int i = 1; i < N; i++)
	{
		if(time < t[i] && time > t[i-1])
		{
			return (x[i-1]+(x[i]-x[i-1])*(time-t[i-1])/(t[i]-t[i-1]));
		}
	}
	return -1;
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
		double t[N];
		double x[N];
		for(int j = 0; j < N; j++)
		{
			cin >> t[j] >> x[j];
		}
	}
	system("pause");
	return 0;
}

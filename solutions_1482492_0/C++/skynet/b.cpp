#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	double A[2222], T[2222], x[2222];
	cin >> t;
	for (int i=1;i<=t;i++)
	{		
		int n, a;
		double d;
		cin >> d >> n >> a;
		for (int j=0;j<n;j++)
			cin >> T[j] >> x[j];
		for (int j=0;j<a;j++)
			cin >> A[j];
		cout << "Case #" << i << ": " << endl;
		cout << setprecision(8) << setiosflags(ios::fixed);
		for (int j=0;j<a;j++)
		{					
			double res = -1;
			double rest = 0;
			if (x[n-1] < d)
			{
				double v = 0;
				if (n>1)
					v = (x[n-1]-x[n-2])/(T[n-1]-T[n-2]);
				double AE = A[j]/2;
				double BE = v;
				double CE = -x[n-1];
				double DE = BE*BE-4*AE*CE; // >0 always in that case
				double rr = (-BE+sqrtl(DE))/2/AE;
				rest += rr;
			}
			for (int h=0;h<n-1;h++)
				if (x[h]<=d)
				{
					double v = ((x[h+1]-x[h])/(T[h+1]-T[h]));
					double AE = A[j];
					double BE = 2*(A[j]*T[h]-v);
					double CE = A[j]*T[h]*T[h]-2*x[h];
					double DE = BE*BE-4*AE*CE;
					if (DE>0)
					{
						double t1 = (-BE-sqrtl(DE))/AE/2;
						double t2 = (-BE+sqrtl(DE))/AE/2;
						if (t1>=0 && t1<=T[h+1]-T[h])
						{
							res = T[h]+t1;
							break;
						}
						else if (t2>=0 && t2<=T[h+1]-T[h])
						{
							res = T[h]+t2;
							break;
						}
					}
				}
			if (n==1)
			{
				if (x[0]>=d)
					cout << sqrtl(d*2/A[j]) << endl;
				else
					cout << max(T[0]+(long double)rest, sqrtl(d*2/A[j])) << endl;
			}
			else
			{
				if (res == -1 || A[j]*res*res/2>=d)
					cout << sqrtl(d*2/A[j]) << endl;
				else
					cout << T[n-1] + rest << endl;
			}
		}		
	}
	return 0;
}
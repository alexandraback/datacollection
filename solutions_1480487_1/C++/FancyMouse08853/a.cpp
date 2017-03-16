#include<iostream>
#include<iomanip>
using namespace std;

const int Max = 200;
int main()
{
	cout<<setiosflags(ios::fixed)<<setprecision(6);
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		int n, a[Max];
		cin>>n;
		int X = 0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			X += a[i];
		}
		cout<<"Case #"<<_<<":";
		for(int i=0;i<n;i++)
		{
			double l, r;
			l = 0.;
			r = 1. + 1e-8;
			while(r-l > 1e-8)
			{
				double mid = (l+r) * .5;
				double threshold = X*mid + a[i];
				double ratio = 0.;
				for(int j=0;j<n;j++)
					if(a[j] < threshold)
						ratio += (threshold-a[j]) / X;
				if(ratio < 1.)
					l = mid;
				else
					r = mid;
			}
			cout<<" "<<l*100.;
		}
		cout<<endl;
	}
}

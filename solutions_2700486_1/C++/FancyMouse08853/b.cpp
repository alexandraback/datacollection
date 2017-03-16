#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double C(double n, double m)
{
	//cout<<"C("<<n<<","<<m<<")"<<endl;
	if(n-m < m)
		m = n-m;
	double result = 1.;
	for(int i=0;i<m;i++)
	{
		result *= n-i;
		result /= 1+i;
	}
	return result;
}
int abs(int n) { return n<0 ? -n : n; }
int main()
{
	cout<<setprecision(9);
	int T;
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		int N,X,Y;
		cin>>N>>X>>Y;
		X = abs(X);
		int level = -1;
		int cur = 0;
		while(cur <= N)
		{
			level++;
			cur += 4*level+1;
		}
		int curlevel = (X+Y)/2;
		int curboundary = 2*curlevel;
		double result = -1.;
		if(curlevel < level)
			result = 1.;
		else if(curlevel > level)
			result = 0.;
		else
		{
			int cnt = 4*level+1;
			N -= cur-cnt;
			result = 0.;
			if(X == 0)
				result = N==2*curboundary+1 ? 1.0 : 0.0;
			else
			{
				for(int i=0;i<=N;i++)
				{
					int negative = 0;
					if(X+i <= curboundary)
						negative = curboundary*2-X-i+1;
					if(i+negative <= N)
						result += C(N,i);
				}
				result /= pow(2.0, N);
			}
		}
		cout<<"Case #"<<_<<": "<<result<<endl;
	}
	return 0;
}

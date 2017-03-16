#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
double solve(int M,int x)
{
	double ans=1;
	double chose=1;
	for(int i=1;i<=x;++i)
	{
		chose *= M+1-i;
		chose /= i;
		ans += chose;
	}
	return ans/pow(2.0,M);
}
int main()
{
	int T;
	cin >> T;
	int idx=0;
	while(T--)
	{
		++idx;
		long long N,X,Y;
		cin >>  N >> X >> Y;
		if(X<0)X=-X;
		long long n=(X+Y)/2+1;
		if(N+n>=2*n*n)
		{
			cout << "Case #"<<idx<<": 1.0"<<endl;
			continue;
		}
		--n;
		long long M=N+n-2*n*n;
		if(M<=Y || X==0)
		{
			cout << "Case #"<<idx<<": 0.0"<<endl;
			continue;
		}
		long long H=X+Y;
		++Y;
		if(M>=(Y+H))
		{
			cout << "Case #"<<idx<<": 1.0"<<endl;
			continue;
		}
		double ans = solve(M,M-Y);
		cout << "Case #"<<idx<<": "<<ans<<endl;
	}
	return 0;
}

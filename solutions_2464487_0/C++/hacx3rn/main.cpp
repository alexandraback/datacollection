#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cmath>
using namespace std;
long long r,t;
long long calc(long long n)
{
    long long result=n*(2*n+2*r-1);
    return result;
}
long long solve()
{
    double dr=r;
    double dt=t;
    double result=(1-2.0*dr+sqrt((2*dr-1)*(2*dr-1)+8*dt) )/4.0;
    return result;
}
int main(int argc, char **argv)
{
	int tc=0;
	cin>>tc;
	for (int cc = 1; cc <= tc; ++cc)
	{
        cin>>r>>t;
        long long result=solve();
        while(calc(result)>t)
            result--;
        while(calc(result)<=t)
            result++;
        result--;
        cout<<"Case #"<<cc<<": "<<result<<endl;
	}
	return 0;
}

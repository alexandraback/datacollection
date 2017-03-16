#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int T;
double r,t;
double ans;
long long rr,tt,x;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		cin >> rr >> tt;
		r=rr;t=tt;
		ans = sqrt((2*r-1)*(2*r-1)/16+t/2)-(2*r-1)/4;
		x=ceil(ans)+1;
		while(tt-2*x*x-(2*rr-1)*x<0) x--;
		cout << "Case #" << i << ": " << x << endl;
	}
	return 0;
}

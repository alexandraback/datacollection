#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
long long r,t;
inline long long func(long long n)
{
		double x=1.0*n*(4.*n+4.*r-2)/2;
		if(x<t || fabs(x-t)<1e-9)return -1;
		else return 1;
		long long ans=2*(r-1)-t/n+2*n;
		if(t%n==0)return ans;
		if(ans>=0)return 1;
		else return -1;
}
int main()
{
		int T;
		cin >> T;
		int idx = 0;
		while(T--)
		{
				++idx;
				cin >> r >> t;
				long long ans=0;
				long long maxn = 1<<30,minn=0;
				while(maxn > minn)
				{
						long long mid =(maxn+minn)/2;
						if(mid==minn)
						{
							long long f=func(maxn);
							if(f<=0)minn=maxn;
							break;
						}
			//			long long f=2*mid*mid+(2*(r-1))*mid;
						long long f=func(mid);
						if(f>0)
								maxn=mid-1;
						else if(f<0)
								minn=mid;
						else 
						{
								minn = mid;
								break;
						}
				}
				cout << "Case #"<<idx<<": "<<minn << endl;
		}
}

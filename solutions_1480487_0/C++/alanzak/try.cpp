// Author : Vivek Hamirwasia

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<cstring>
#define LLD long long int
using namespace std;
int N;
long long int points[501];
long long int mx;
long long int lo,hi,mid,s;
long long int mul=100000;

int satisfy(long long int val,int i)
{
	long double m = (long double)val/((long double)mul*mul);
	long double  pool = 1-m;
	long double req;
	int j;
	
	for(j=0;j<N;j++)
	{
		if(j==i)
			continue;
		req = (long double)(points[i] + m*s - points[j])/(long double)s;
		if(req>pool)
			return 1;
		pool=pool-req; 

	}

	return 0;

}

int main()
{
	long long int ans=100000;
	mx=ans*ans;
	
	int i,j,T;
	cin>>T;
	for(int k=0;k<T;k++)
	{
		printf("Case #%d: ",k+1);
		s=0;
		cin>>N;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&points[i]);
			s+=points[i];
		}
		double y;

		for(i=0;i<N;i++)
		{
			lo=0;
			ans=hi=2*mx;
			

			while(lo<=hi)
			{
				mid=(lo+hi)/2;
				if(satisfy(mid,i))
				{
					if(mid<ans)
					ans=mid;
					hi=mid-1;
				}
				else
					lo=mid+1;
			}

			y=(( double)ans)/(double)100000000.0;
			printf("%.7lf ",y);


		}

		printf("\n");


	}
	return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
//#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#define eps 1e-12
#define MAX 1000000000
using namespace std;

double a[300];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int re,i,j,k,m,n;
	double y;
	cin>>re;
	int cases=1;
	while(re--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		double sum=0;
		for(i=0;i<n;i++)
			sum+=a[i];
		cout<<"Case #"<<cases++<<":"; 
		for(i=0;i<n;i++)
		{
			double low,high,mid,ans;
			
			low=0;
			high=1;
			int T=100;
			ans=1;
			while(T--)
			{
				mid=(low+high)/2;
				double vote=a[i]+sum*mid;
				double tmp=mid;
				for(j=0;j<n;j++)
				{
					if(i==j)
					continue;
					if(vote-a[j]>=0)
					tmp+=(vote-a[j])/sum;
				}
				
				if(tmp>=1)//ok
				{
					ans=mid;
					high=mid;
				}
				else  low=mid;
					
			}
			
			printf(" %.6lf",ans*100);
			
			
			
				
		}
		cout<<endl;
		
	}
}
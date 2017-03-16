
#include<malloc.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
bool func(int a, int b)
{
	if(b<a)
		return true;
	return false;
}

int main()
{

	int t;
	cin>>t;
	rep(x,t)
	{
		int n;
		cin>>n;
		int arr[210];
		rep(i,n)
			cin>>arr[i];
		int sum=0,cp[210];
		rep(i,n)
		{
			sum+=arr[i];
			cp[i]=arr[i];
		}
		sort(cp,cp+n);
		cout<< "Case #"<<x+1<<":";

		int tot=0,pre=0;
		rep(i,n)
		{
			int num=arr[i];
			while(1)
			{
				pre=tot;
				tot=0;
				rep(j,n)
				{
					if(arr[j]<num )
						tot+=num-arr[j];
				}
				if(tot>=sum)
					break;
				else
					num++;
			}
			double x=( ((num-arr[i])*100.0)/sum )  -  ((100*  (tot-sum*1.0))/sum)/(tot-pre) ; 
			if(x<=0.00001)
				x=0;
			printf(" %.6lf",x);

		}
		cout<<endl;

	}
	return 0;
}

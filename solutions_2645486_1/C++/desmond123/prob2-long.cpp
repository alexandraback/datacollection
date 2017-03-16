#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	vector<long long int> ans;
	int t;
	cin>>t;
	int z=0;
	while(t--)
	{
		
		long long e,r,n;
		cin>>e>>r>>n;
		vector<long long int> v;
		long long a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);
		}
		long long c =e;
		long long sum =0;
		for(int i=0;i<n;i++)
		{
			long long count = 0;
			for(int j=i;j<n&&v[j]<=v[i];j++,count++);
			long long max = c+r*count - e;
			if(max>c)
				max=c;
			if(i+count>=n)
				max = c;
			if(max<0)
				max=0;
			c+=(r-max);
			sum+=max*v[i];
			//cout<<n<<'\t'<<max<<'\t'<<c<<endl;
		}
		ans.push_back(sum);
		//cout<<"Case #"<<++z<<": "<<sum<<endl;
		//cout<<endl;

	}

	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}
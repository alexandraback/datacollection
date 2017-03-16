#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	vector<int> ans;
	int t;
	cin>>t;
	int z=0;
	while(t--)
	{
		
		int e,r,n;
		cin>>e>>r>>n;
		vector<int> v;
		int a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);
		}
		int c =e;
		int sum =0;
		for(int i=0;i<n;i++)
		{
			int count = 0;
			for(int j=i;j<n&&v[j]<=v[i];j++,count++);
			int max = c+r*count - e;
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
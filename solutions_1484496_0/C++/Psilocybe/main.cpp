#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int MAXN = 2000003;
const double eps = 1e-9;
int arr[505];
int n;

bool solve(int mask1, int mask2)
{
	int m1[20],sz1=0,m2[20],sz2=0,s1=0,s2=0;

	for(int i=0;i<n;i++)
	{
		if(mask1 & 1<<i)
			s1 += (m1[sz1++] = arr[i]);
		if(mask2 & 1<<i)
			s2 += (m2[sz2++] = arr[i]);
	}
	
	if(!sz1 || !sz2 || s1 != s2)
		return false;

	if(s1 == s2)
	{
		bool f = true;

		sort(m1,m1+sz1);
		sort(m2,m2+sz2);
		for(int i=0;i<sz1;i++)
			if(m1[i] != m2[i])
				f = false;
		if(f)
			return false;
	}
	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int test;
	cin>>test;
	
	map<int, vector<int> > mp;

	for(int t=0;t<test;t++)
	{
		cout<<"Case #"<<t+1<<":"<<endl;
		
		cin>>n;

		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		int ans1 = -1,ans2 = -1;
		for(int mask=0;mask<(1<<20);mask++)
		{
			int sum = 0;
			
			for(int i=0;i<n;i++)
				if(mask & 1<<i)
					sum += arr[i];

			vector<int>& v = mp[sum];
			for(int i=0;i<v.size();i++)
				if(solve(mask,v[i]))
				{
					ans1 = v[i];
					ans2 = mask;
					break;
				}
			if(ans1 != -1)
				break;
			else
				v.push_back(mask);

		}
		if(ans1 == -1)
			cout<<"Impossible"<<endl;
		else
		{
			for(int i=0;i<n;i++)
				if(ans1 & 1<<i)
					cout<<arr[i]<<" ";
			cout<<endl;
			for(int i=0;i<n;i++)
				if((ans2 & 1<<i))
					cout<<arr[i]<<" ";
			cout<<endl;
		}

	}
		
	return 0;
}
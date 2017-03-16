#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	vector<long long> ans;
	int t;
	cin>>t;
	while(t--)
	{
		long long r,s;
		cin>>r>>s;
		long long a = 2*r+1;
		long long int an = (4-2*a+sqrt((2*a-4)*(2*a-4)+32*s))/8;
		ans.push_back(an);

	}

	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}
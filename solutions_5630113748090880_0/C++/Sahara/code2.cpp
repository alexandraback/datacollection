#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	for(int k = 1; k<=t; k++)
	{
		cin>>n;
		int ar_size = (2*n-1)*n;
		int a[ar_size];
		int b[2501] = {0};
		vector<int> v;
		for(int i=0;i<ar_size;i++)
		{
			cin>>a[i];
			b[a[i]]++;
		}
		for(int i=1;i<=2500;i++)
		{
			
			if(b[i]%2 == 1)
				v.push_back(i);
		}
		sort(v.begin(),v.end());
		cout<<"Case #"<<k<<": ";
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i]<<" ";
		}
	cout<<endl;	
	}
	return 0;
}	
			

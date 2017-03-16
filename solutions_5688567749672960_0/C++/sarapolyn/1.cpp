#include<bits/stdc++.h>
using namespace std;
int rev(int n)
{
	vector<int> a(0);
	while(n>0)
	{
		a.push_back(n%10);
		n/=10;
	}
	int res =0;
	for(int i=0;i<a.size();i++)
	{
		res = 10*res + a[i];
	}
	return res;
}
int main()
{
	int n,t,i,ans;
	vector<int> arr(1000006,0);
	arr[1] = 1;
	for(i=2;i<arr.size();i++)
	{
		if(rev(rev(i))==i && rev(i)<i)
			arr[i] = 1+min(arr[rev(i)], arr[i-1]);
		else
			arr[i] = arr[i-1]+1;
	}
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		cout<<"Case #"<<i+1<<": "<<arr[n]<<endl;
	}
	return 0;
}
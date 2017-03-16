#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9+7
int arr[2550];
int main()
{
 //  freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ll t;
  cin>>t;
  for(ll test=1;test<=t;test++)
  {
  	for(int i=0;i<2501;i++) arr[i]=0;
    int n,a;
	cin>>n;
	for(int i=0;i<2*n-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a;
			arr[a]++;
		}
	}  	
  	
  	vector<int> v;
  	for(int i=1;i<=2500;i++)
  	{
  		if(arr[i]&1)
  		{
  			v.push_back(i);
  		}
  		
  	}
  	sort(v.begin(),v.end());
  	      cout<<"Case #"<<test<<": ";

	  for(int i=0;i<v.size();i++)
  	 cout<<v[i]<<" ";
  	 cout<<endl;
  	
  	
  	
    }
  return 0;
}

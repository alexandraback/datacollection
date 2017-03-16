
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(i=a;i<b;i++)
#define vi vector<int>

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	int i,j,k;
	FOR(i,1,t+1)
	{
		int n;
		cin>>n;
		vector<double> d1(n);
		vector<double> d2(n);
		FOR(j,0,n)
			cin>>d1[j];
		FOR(j,0,n)
			cin>>d2[j];
		sort(d1.begin(),d1.end());
		sort(d2.begin(),d2.end());
		int i1=0;
		int i2=0;
		int ans=0;
		while(i1<n)
		{
			if(d1[i1]<d2[i2])
				i1++;
			else
			{
				ans++;
				i1++;
				i2++;
			}
		}
		int ans2=0;
		i1=n-1;
		i2=n-1;
		while(i1>=0)
		{
			if(d1[i1]>d2[i2])
			{
				i1--;
				ans2++;
			}
			else
			{
				i1--;
				i2--;
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<" "<<ans2<<endl;
	}
				
	return 0;
}
	

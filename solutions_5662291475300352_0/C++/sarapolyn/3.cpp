#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	double n,t,i,ans,r,c,j,k,d,h,m,d1,d2,m1,m2;
	cin>>t;
	for(int it=0;it<t;it++)
	{
		cin>>n;
		ans = 0;
		vector<pair<double, double> > arr(0);
		for(i=0;i<n;i++)
		{
			cin>>d>>h>>m;
			for(j=0;j<h;j++)
			{
				arr.push_back(make_pair(m+j,d));
			}
		}
		//cout<<arr.size()<<endl;
		if(arr.size()<2)
		{
			ans = 0;
		}
		else
		{
			//cout<<arr[0].first<<" "<<arr[1].first<<endl;
			sort(arr.begin(), arr.end());
			//cout<<arr[0].first<<" "<<arr[1].first<<endl;
			d1 = arr[0].second;
			d2 = arr[1].second;
			m1 = arr[0].first;
			m2 = arr[1].first;
			//cout<<m1<<" "<<m2<<endl;
			if(arr[0].first==arr[1].first)
			{
				ans = 0;
			}
			else if(d1>=d2)
			{
				if(((360-d2)*m2/m1)+d1-360 >= 360)
					ans = 1;
				else
					ans = 0;
			}
			else
			{
				if(((360-d1)*m1/m2)+d2 <= 360)
				{
					double d3 = d2+(360/m2)*((d2-d1)/((360/m1)-(360/m2)));
					if(((360-d3)*m2/m1)+d3-360 >= 360)
						ans = 1;
					else
						ans = 0;
				}
				else
					ans = 0;
			}
		}
		cout<<"Case #"<<it+1<<": "<<ans<<endl;
	}
	return 0;
}
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

pair<double,int> a[2000];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for (int ii=0;ii<t;ii++)
	{
		cout<<"Case #"<<ii+1<<": ";
		cin>>n;
//		cout<<n<<endl;
		for (int i=0;i<n;i++)
		{
			double k;
			cin>>k;
			a[i]=make_pair(k,1);
		}
		for (int i=0;i<n;i++)
		{
			double k;
			cin>>k;
			a[i+n]=make_pair(k,2);
		}
		sort(a,a+2*n);
		int k=0;
		int ans=0,ans2=0;
		for (int i=2*n-1;i>=0;i--)
		{
			if (a[i].second==1)
				k++;
			else	
				k--;
			ans=max(ans,-k);
			ans2=max(ans2,k);
//			cout<<k<<endl;
		}
		cout<<n-ans<<' '<<ans2<<"\n";
	}
		
}
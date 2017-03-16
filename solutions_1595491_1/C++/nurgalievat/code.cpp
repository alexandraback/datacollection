#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int n,t,s,p,ans;
int sum[110];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cin>>n>>s>>p;
		for(int i=0;i<n;i++)
			cin>>sum[i];
		sort(sum,sum+n,greater<int>());
		ans=0;
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			a=b=c=sum[i]/3;
			int m = sum[i]%3;
			if(a>=p || (m!=0 && a+1>=p))
			{
				ans++; //already greater
				continue;
			}
			if(s)
			{
				if((m==0 && a+1>=p && a!=0)||(m==2 && a+2>=p))
				{
					ans++;
					s--;
				}
			}
		}
		cout<<"Case #"<<T<<": "<<ans<<endl;
	}
	return 0;
}
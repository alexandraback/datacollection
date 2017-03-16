#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		ll a,n;
		cin>>a>>n;
		ll M[n];
		ll i;
		for(i=0;i<n;i++)
			cin>>M[i];
		if(a==1)
		{
			cout<<"Case #"<<u-t<<": "<<n<<endl;
			continue;
		}
		sort(M,M+n);
		ll j,temp=a,ans=0,cnt;
		for(j=0;j<n;j++)
		{
			cnt=0;
			while(temp<=M[j])
			{
				temp=(2*temp-1);
				cnt++;
			}
			if(cnt>(n-j))
			{
				if((ans+n-j)>=n)
					ans=n;
				else
					ans+=(n-j);
				break;
			}
			else if((ans+cnt)<n)
				ans+=cnt;
			else
			{
				ans=n;
				break;
			}
			temp+=M[j];
		}
		cout<<"Case #"<<u-t<<": "<<ans<<endl;
	}
	return 0;
}
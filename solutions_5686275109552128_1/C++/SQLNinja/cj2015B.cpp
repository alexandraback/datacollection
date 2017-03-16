#include<bits/stdc++.h>
#define N 10000
using namespace std;
long long a[N];
int main()
{
    freopen("b.in","r",stdin);
    freopen("ansb.out","w",stdout);
	int t;
	cin>>t;
	for(long long tc=1;tc<=t;tc++)
	{
		long long xx=0,n;
        cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>xx)xx=a[i];
		}
		long long ans=xx;
		for(long long i=1;i<=xx;i++)
		{
			long long curr=0,maxx=0;
			for(long long j=1;j<=n;j++)
			{
				if(a[j]>i)
				{
					curr += (a[j] / i)+((a[j]%i==0)?0:1)-1;
					maxx=max(maxx,i);
				}
				else maxx=max(maxx,a[j]);
			}
			curr+=maxx;
			if(curr<ans)
                ans=curr;
		}
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
	return 0;
}

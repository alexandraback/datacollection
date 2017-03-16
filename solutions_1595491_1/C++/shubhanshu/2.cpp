
#include<malloc.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
	int t;
	cin>>t;
	int n,s,p,arr[110];
	int ans=0,tot=0;
	rep(i,t)
	{
		ans=0;
		tot=0;
		cin>>n>>s>>p;
		rep(j,n)
			cin>>arr[j];
		rep(j,n)
		{
			if(arr[j]%3==1)
			{
				if(arr[j]/3 + 1 >= p)
					ans++;
			}
		}
		rep(j,n)
		{
			if(arr[j]==0 )
			{
				if(p==0)
					ans++;
			}
			else if(arr[j]%3==0)
			{
				if(arr[j]/3 >=p)
					ans++;
				else if((arr[j]/3 + 1 >=p) && ( tot<s ) )
				{
					tot++;
					ans++;
				}
					
			}
		}
		rep(j,n)
		{
			if(arr[j]%3==2)
			{
				if(arr[j]/3 +1 >=p )
					ans++;
				else if( (arr[j]/3 + 2>=p) && (tot<s) )
				{
					tot++;
					ans++;

				}
			}
		}
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}

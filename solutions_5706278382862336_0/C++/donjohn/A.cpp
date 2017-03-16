#include<iostream>
#include<string>
#include<cstdio>
#include<limits>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define SMALL
//#define LARGE

int main()
{


	#ifdef SMALL
		freopen("A-small-attempt1.in","rt",stdin);
		freopen("A-small.out","wt",stdout);
	#endif

	#ifdef LARGE
		freopen("A-large-attempt0.in","rt",stdin);
		freopen("A-large.out","wt",stdout);
	#endif

	int i,t;
	cin>>t;
	
	for(i=1;i<=t;i++)
	{
		long long int ans=0,j=0,p,q,temp=1;
		cin>>p;
		cin.ignore(256,'/');
		cin>>q;
		
		while(temp<=q)
		{
			temp*=2;
		}
		temp/=2;
		if(temp!=q)
			ans=-1;
		else
		{
			for(j=1;q>=1;j++)
			{
				if(p>=(q/2))
					break;
				q=q/2;				
			}
			ans=j;
		}
		
		if(ans==-1)
			cout<<"Case #"<<i<<": impossible"<<endl;
		else
			cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	
	return 0;
}

#include<bits/stdc++.h>
#define MAXI 100000000
using namespace std;
struct pro
{
	int maxi,breaks;
}brr[10001];
int main()
{
	int t,i,j,ii,value,ans,temp,arr[100001],d,jval,maxi,ival,cost,breaks;		
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++)
	{
		ans=0;
		maxi=0;
		scanf("%d",&d);
		for(i=0;i<d;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+d);
		ans=MAXI;
		//value=ceil((double)arr[0]/2);
		//cout<<"val="<<value<<endl;
		for(i=1;i<=arr[d-1];i++)
		{
			breaks=i;
			//cout<<endl<<endl<<endl;
			for(j=0;j<d;j++)
			{
				breaks+=ceil((double)arr[j]/i) - 1;
				//cout<<breaks<<endl;
				
			}
		//	cout<<"breaks="<<breaks<<endl;
			ans=min(ans,breaks);
		}
		cout<<"Case #"<<ii<<": "<<ans+maxi<<endl;
		
	}
	
}

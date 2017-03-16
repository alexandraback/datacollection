#include<iostream>
using namespace std;

int main()
{
int t,n,arr[101],s,p,k,i, pre[31]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
int cnt_wo_surp, cnt_with_surp, best, ans;
cin>>t;
for(k=1;k<=t;k++)
{
	cout<<"Case #"<<k<<": ";
	cnt_wo_surp=0;
	cnt_with_surp=0;
	cin>>n>>s>>p;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>=2 && arr[i]<=28)
		{
			best = pre[arr[i]];
			
			if(best>=p)
			cnt_wo_surp++;
			else if(best+1==p && ((arr[i]+2)%3!=0) )
			cnt_with_surp++;
		}
		else
		{
			best = pre[arr[i]];
			if(best>=p)
			cnt_wo_surp++;
		}
	}
	
	if(cnt_with_surp>s)
	ans = cnt_wo_surp + s;
	else
	ans = cnt_wo_surp + cnt_with_surp;
	cout<<ans<<'\n';
}

return(0);
}

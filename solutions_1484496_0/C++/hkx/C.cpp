#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	freopen("C-small-attempt0.in","r",stdin);freopen("out.txt","w",stdout);
	int T,cas=0;
	cin>>T;
	int N;
	int a[600];
	bool s[2000000];
	int i;
	while(T--)
	{
		cas++;
		printf("Case #%d:\n",cas);
		memset(s,0,sizeof(s));
		cin>>N;
		for(i=1;i<=N;i++) cin>>a[i];
		int k,SS;
		for(k=1;k<(1<<N);k++)
		{
			int num[22];
			int temp=k;
			//cout<<k<<endl;
			for(i=N;i>=1;i--)
			{
				if(temp&1) num[i]=1;
				else num[i]=0;
				temp>>=1;
			}
			int sum=0;
			for(i=1;i<=N;i++)
			{
				if(num[i]) sum+=a[i];
			}
			if(s[sum])
			{
				for(i=1;i<=N;i++)
				{
					if(num[i]){cout<<a[i];break;}
				}
				i++;
				for(;i<=N;i++)
				{
					if(num[i]){cout<<" "<<a[i];}
				}
				cout<<endl;
				SS=sum;
				break;
			}
			else s[sum]=1;
		}
		for(k=1;k<(1<<N);k++)
		{
			int num[22];
			int temp=k;
			//cout<<k<<endl;
			for(i=N;i>=1;i--)
			{
				if(temp&1) num[i]=1;
				else num[i]=0;
				temp>>=1;
			}
			int sum=0;
			for(i=1;i<=N;i++)
			{
				if(num[i]) sum+=a[i];
			}
			if(SS==sum)
			{
				for(i=1;i<=N;i++)
				{
					if(num[i]){cout<<a[i];break;}
				}
				i++;
				for(;i<=N;i++)
				{
					if(num[i]){cout<<" "<<a[i];}
				}
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}

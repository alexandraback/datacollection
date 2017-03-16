#include<bits/stdc++.h>
using namespace std;
int A[2010];
int main()
{
	int T;
	cin>>T;
	for(int idx=1;idx<=T;idx++)
	{
		int D;
		cin>>D;
		
		for(int i=0;i<D;i++)
		{
			
			cin>>A[i];
		}
		int ans = 1000100;
		
		for(int i=1;i<=1000;i++)
		{
			int tp = 0;
			for(int j=0;j<D;j++)
			{
				if(A[j]>i)
				{
					tp += (A[j]+i-1)/i - 1;
				}
			}
			ans = min(ans,tp+i);
		}
		
		cout<<"Case #"<<idx<<": "<<ans<<'\n';
	}
}

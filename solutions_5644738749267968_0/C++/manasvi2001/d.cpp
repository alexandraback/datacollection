#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		int n,i,j,k,wans=0,dwans=0;
		cin>>n;
		double N[n],K[n];
		int visN[n],visK[n];
		memset(visN,0,sizeof(visN));
		for(i=0;i<n;i++)
			cin>>N[i];
		for(i=0;i<n;i++)
			cin>>K[i];
		sort(N,N+n);
		sort(K,K+n);
		j=n-1,k=0;
		for(i=n-1;i>=k;i--,j--)
		{
			if(N[i]>K[j]&&visN[i]==0)
			{
				dwans++;
				visN[i]=1;
			}
			else
			{
				visN[k]=1;
				k++;
				i++;
			}
		}
		memset(visK,0,sizeof(visK));
		k=0;
		for(i=0;i<n;i++)
		{
			if(visK[n-1]==1)
				break;
			for(j=k;j<n;j++)
			{
				if(visK[j]==0&&N[i]<K[j])
				{
					visK[j]=1;
					k=j+1;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(visK[i]==0)
				wans++;
		}
		cout<<"Case #"<<u-t<<": "<<dwans<<" "<<wans<<endl;
	}
	return 0;
}
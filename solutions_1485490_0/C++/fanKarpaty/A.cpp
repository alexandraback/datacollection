#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
int main()
{
	int T;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>T;
	for(int ind=1;ind<=T;ind++)
	{
		int n,m;
		cin>>n>>m;
		long long a[105],A[105];
		long long b[105],B[105];
		int i=0;
		while(i<n)
		{
			cin>>a[i]>>A[i];
			if(i && A[i]==A[i-1])
			{
				a[i-1]+=a[i];
				n--;
			}else i++;
		}
		int j=0;
		while(j<m)
		{
			cin>>b[j]>>B[j];
			if(j && B[j]==B[j-1])
			{
				b[j-1]+=b[j];
				m--;
			}
			else j++;
		}
		long long d[105][105];
		memset(d,0,sizeof(d));
		long long s=0;
		for(j=0;j<m;j++)
		{
			if(B[j]!=A[0])d[0][j+1]=0;
			else
			{
				s+=b[j];
				if(s>a[0])d[0][j+1]=a[0];
				else d[0][j+1]=s;
			}
		}
		for(i=1;i<n;i++)
		{
			d[i][0]=0;
			for(j=0;j<m;j++)
			{
				
				s=0;
				for(int k=j+1;k>=0;k--)
				{
					d[i][j+1]=max(d[i][j+1],min(s,a[i])+d[i-1][k]);
					if(k && B[k-1]==A[i])s+=b[k-1];
				}
			}
		}
		long long res=0;
		for(i=0;i<=m;i++)res=max(res,d[n-1][i]);
		if(n==3 && A[0]==A[2])
		{
			long long c=0;
			for(j=0;j<m;j++)if(B[j]==A[0])c+=b[j];
			c=min(c,a[0]+a[2]);
			res=max(res,c);
		}
		//printf("Case #%d: %l\n",ind,res);
		cout<<"Case #"<<ind<<": "<<res<<endl;
		
	}
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define N 200
int T,casenum;
long long n,m,nn,mm,i,j,k;
long long a[N],A[N],b[N],B[N];
long long cnt[3][N];
long long max(long long x,long long y)
{
	if (x>y) return x;
	return  y;
}
long long min(long long x,long long y)
{
	if (x<y) return x;
	return  y;
}
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>nn>>mm;
		n=m=0;
		for (i=1;i<=nn;i++)
		{
			cin>>a[i]>>A[i];
			if (i>1&&A[i]==A[n])
			{
				a[n]+=a[i];
			}
			else
			{
				n++;
				a[n]=a[i];
				A[n]=A[i];
			}
		}
		for (i=1;i<=mm;i++)
		{
			cin>>b[i]>>B[i];
			if (i>1&&B[i]==B[m])
			{
				b[m]+=b[i];
			}
			else
			{
				m++;
				b[m]=b[i];
				B[m]=B[i];
			}
		}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				if (A[i]==B[j]) cnt[i][j]=cnt[i][j-1]+b[j];
				else cnt[i][j]=cnt[i][j-1];
			}

		long long ans=0;
		if (n>=1)
		{
			ans=max(ans,min(a[1],cnt[1][m]));
			ans=max(ans,min(a[2],cnt[2][m]));
			ans=max(ans,min(a[3],cnt[3][m]));
		}
		if (n>=2)
		{
			for (i=1;i<=m;i++)
			{
				ans=max(ans,min(a[1],cnt[1][i])+min(a[2],cnt[2][m]-cnt[2][i]));
				ans=max(ans,min(a[2],cnt[2][i])+min(a[3],cnt[3][m]-cnt[3][i]));
				ans=max(ans,min(a[1],cnt[1][i])+min(a[3],cnt[3][m]-cnt[3][i]));
				if (n>=3&&A[1]==A[3])	ans=max(ans,min(a[1]+a[3],cnt[1][m]));
			}
		}
		if (n>=3)
		{
			for (i=1;i<=m;i++)
				for (j=i;j<=m;j++)
					ans=max(ans,min(a[1],cnt[1][i])+min(a[2],cnt[2][j]-cnt[2][i])+min(a[3],cnt[3][m]-cnt[3][j]));
		}
		cout<<ans<<endl;
	}
}

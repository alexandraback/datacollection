#include<iostream>
#include<algorithm>
#define MAXN 1000
using namespace std;
int main()
{
	int i,j,N,T,l1,l2,r1,r2,ans;
	double a[MAXN],b[MAXN];
	freopen("QR_D.in","r",stdin);
	freopen("QR_D.out","w",stdout);
	cin>>T;
	for (int k=0;k<T;k++)
	{
		cin>>N;
		for (i=0;i<N;i++) cin>>a[i];
		for (i=0;i<N;i++) cin>>b[i];
		sort(a,a+N);
		sort(b,b+N);
		l1=0;l2=0;r1=N-1;r2=N-1;ans=0;
		while (l1<=r1&&a[l1]<b[l2])
		{
			l1++;r2--;
		}
		while (l1<=r1)
		{
			while (l1<=r1&&a[r1]>b[r2])
			{
				r1--;
				r2--;
				ans++;
			}
			while (l1<=r1&&a[r1]<b[r2])
			{
				l1++;
				r2--;
			}
		}
		cout<<"Case #"<<k+1<<": "<<ans<<" ";
		for (i=0,j=0;i<N&&j<N;i++,j++)
		{
			while (a[i]>b[j]&&j<N) j++;
			if (j>=N) break;
		}		
		cout<<N-i<<endl;
	}
	return 0;
}
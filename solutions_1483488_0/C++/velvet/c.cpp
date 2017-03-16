#include <cstdio>
#include <iostream>
const int d[]={1,10,100,1000,10000,100000,1000000,10000000};
using namespace std;
int L,A,B;
int a[10];
int len(int a)
{
	int ret=0;
	while (a) a/=10,ret++;
	return ret;
}
int calc(int n)
{
	int m=n,cnt=0;
	bool flag;
	
	for (int i=1;i<L;i++)
	{
		m=m%d[L-1]*10+m/d[L-1];
		if (m>n && m<=B)
		{
			flag=0;
			for (int j=1;j<=cnt;j++)
				if (a[j]==m) {flag=1;break;}
			if (!flag) a[++cnt]=m;
		}
	}
	return cnt;
}
int main()
{
	int T;
	cin>>T;
	for (int cas=1;cas<=T;cas++)
	{
		long long ans=0;
		cin>>A>>B;
		L=len(A);
		printf("Case #%d: ",cas);
		for (int n=A;n<B;n++)
			ans+=calc(n);
		cout<<ans<<endl;
	}
	return 0;
}

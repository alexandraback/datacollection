#include <bits/stdc++.h>
using namespace std;
long rev(long x)
{
	long a=0;
	while(x)
	{
		a=a*10+x%10;
		x/=10;
	}
	return a;
}
void solve()
{
	long m,N,r;
	cin>>N;
	long X[1000000];
	X[0]=1;
	for(long i=2;i<=N;i++)
	{
		r=rev(i);

		m=X[i-2]+1;
		

		//while(r<i)
		if(r<i && i==rev(r))
		{
			m=min(m,X[r-1]+1);
			//r*=10;
		}
		X[i-1]=m;
		//cout<<X[i-1]<<' ';
	}	
	cout<<X[N-1];
}
int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i );
		solve();
		printf("\n");
	}
	return 0;
}